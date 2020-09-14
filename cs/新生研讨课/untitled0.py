# -*- coding: utf-8 -*-
"""
Created on Tue May 21 17:35:36 2019

@author: gaochuqing
"""

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
from pyquery import PyQuery as pq
import time
import json

options = webdriver.ChromeOptions()
#	设置无图模式
prefs = {
    'profile.default_content_setting_values': {
        'images': 2
    }
}
options.add_argument('--headless')          # 浏览器隐藏
options.add_argument('--disable-gpu')
options.add_experimental_option('prefs', prefs)        #设置无图模式
browser = webdriver.Chrome(chrome_options=options)
wait = WebDriverWait(browser, 5)


def get_last_page(qq):
    try:
        url = f'https://user.qzone.qq.com/{2110566945}/311'
        browser.get(url)
        try:
            browser.find_element(By.NAME, 'login_frame')  # 发现登陆的frame
        except:
            raise
        else:
            try:
                browser.switch_to_frame('login_frame')  # 发现之后进入login_frame
                login = wait.until(EC.element_to_be_clickable(
                    (By.ID, 'img_out_1141892453')))  # 获取点击按钮  也可以进行输入账号密码
                login.click()  # 进行点击
            except Exception as e:
                raise
        time.sleep(2)
        browser.switch_to_frame('app_canvas_frame')  # 进入switch_to_frame
        page_last = wait.until(EC.presence_of_element_located(
            (By.CSS_SELECTOR, '#pager_last_0 > span'))).text  # 最后一页
        return int(page_last)
    except Exception:
        get_last_page(qq)


def get_page_text(n):
    try:
        doc = pq(browser.page_source)           # 获取页面的html
        items = doc('#msgList > li.feed').items()          # 获取所有的说说
        for item in items:      # 对说说进行分开
            yield {
                'time': item.find('div.box.bgr3 > div.ft > div.info > .c_tx3 > .c_tx').text(),
                'text': item.find('.content').text().lstrip('♡\n')
            }
        text = wait.until(EC.presence_of_element_located((By.ID, f'pager_go_{n-1}')))   # 获取跳转页的输入框
        text.send_keys(n+1)     # 输入下一页
        text.send_keys(Keys.ENTER)      #进行确定
    except:
        browser.close()


def write_page(page):
    with open('qq.txt', 'a', encoding='utf-8') as f:
        for page in get_page_text(page):
            f.write(json.dumps(page, ensure_ascii=False) + '\n')       # 将dict转换为json格式进行保存


if __name__ == '__main__':
    page_last = get_last_page('qq')
    for i in range(1, page_last+1):
        write_page(i)
    browser.close()
