-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
-- Date        : Thu Nov 21 21:08:59 2019
-- Host        : LAPTOP-QEVL8JVR running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               h:/magic_code/lab7_2/lab7_2.srcs/sources_1/ip/dist_mem_gen_0/dist_mem_gen_0_stub.vhdl
-- Design      : dist_mem_gen_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7a100tcsg324-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity dist_mem_gen_0 is
  Port ( 
    a : in STD_LOGIC_VECTOR ( 3 downto 0 );
    spo : out STD_LOGIC_VECTOR ( 7 downto 0 )
  );

end dist_mem_gen_0;

architecture stub of dist_mem_gen_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "a[3:0],spo[7:0]";
attribute x_core_info : string;
attribute x_core_info of stub : architecture is "dist_mem_gen_v8_0_13,Vivado 2019.1";
begin
end;
