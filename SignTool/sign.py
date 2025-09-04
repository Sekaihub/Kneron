import sys
import argparse
import os

if __name__ == '__main__':
    # os.system("ls -l")
    parser = argparse.ArgumentParser()
    parser.add_argument("-t", "--type", type=str, help="[BLp|BLe|BLx|BLw]  Image format")
    parser.add_argument("-i", "--infile", type=str, help="input file")
    parser.add_argument("-p", "--prikey",type=str,help="der file")
    parser.add_argument("-w", "--wrapkey",type=str,help="wrap key for BLw")
    parser.add_argument("-c", "--cert",type=str,help="cert")
    parser.add_argument("--scrtu_fw",type=str,help="scrtu fw file")
    parser.add_argument("--ddr_fw",type=str,help="ddr fw file")
    parser.add_argument("--attr_spi",type=str,help="spi attribute, hex format:0x12341234")
    parser.add_argument("--spi_bl33_addr",type=str,help="spi_bl33_addr, hex format:0x12341234")
    parser.add_argument("--spi_bl33_size",type=str,help="spi_bl33_size, hex format:0x12341234")
    args = parser.parse_args()
    print("args:")
    print(args)
    # print("args.attr_spi:%s" % args.attr_spi)
    # print(hex(int(args.attr_spi,16)))
    header_only = "header_only.bin"
    if args.type == "BLp":
        cmd_orig = f"signtool sign -type {args.type} -pubkeytype rom -prikey {args.prikey} -infile {args.infile} -outfile {header_only}"
    elif args.type == "BLw":
        cmd_orig = f"signtool sign -type {args.type} -pubkeytype image -prikey {args.prikey} -algo aes128 -wrapkey {args.wrapkey} -infile {args.infile} -outfile {header_only}"
    else:
        print("not support")
        exit(1)

    if args.cert != None:
        cmd_cert = f" -cert {args.cert}"
        cmd_orig = cmd_orig + cmd_cert 
    print(cmd_orig)
    os.system(cmd_orig)
    header_only_file_size = os.path.getsize(header_only)
    print("header_only_file_size:%d" % header_only_file_size)

    # SPI
    cmd_attr_spi = ""
    if args.attr_spi != None:
        cmd_attr_spi = f" -attribute 0x80000001={args.attr_spi}"

    # SPI BL33 addr
    cmd_spi_bl33_addr = ""
    if args.spi_bl33_addr != None:
        cmd_spi_bl33_addr = f" -attribute 0x80000005={args.spi_bl33_addr}"

    # SPI BL33 size
    cmd_spi_bl33_size = ""
    if args.spi_bl33_size != None:
        cmd_spi_bl33_size = f" -attribute 0x80000006={args.spi_bl33_size}"

    # SCRTU
    scrtu_fw_size = 0
    cmd_attr_scrtu_fw = ""
    if args.scrtu_fw != None:
        scrtu_fw_size = os.path.getsize(args.scrtu_fw)
    print("scrtu_fw_size:%d" % scrtu_fw_size)
    scrtu_offset = header_only_file_size
    if args.scrtu_fw != None:
        cmd_attr_scrtu_fw = f" -attribute 0x80000002={scrtu_offset}"

    # DDR
    ddr_fw_size = 0
    cmd_attr_ddr_fw = ""
    if args.ddr_fw != None:
        ddr_fw_size = os.path.getsize(args.ddr_fw)
    print("ddr_fw_size:%d" % ddr_fw_size)
    ddr_offset = scrtu_offset + scrtu_fw_size
    if args.ddr_fw != None:
        cmd_attr_ddr_fw = f" -attribute 0x80000003={ddr_offset}"

    # total size
    total_size = header_only_file_size + scrtu_fw_size + ddr_fw_size
    print("total_size:%d" % total_size)
    cmd_total_size = f" -attribute 0x80000004={total_size}"

    final_output = "_final_" + args.infile
    cmd_attr = f"{cmd_attr_spi} {cmd_spi_bl33_addr} {cmd_spi_bl33_size} {cmd_attr_scrtu_fw} {cmd_attr_ddr_fw} {cmd_total_size}"
    
    if args.type == "BLp":
        cmd_final = f"signtool sign -type {args.type} -pubkeytype rom -prikey {args.prikey} -infile {args.infile} -outfile {final_output}" + cmd_attr
    elif args.type == "BLw":
        cmd_final = f"signtool sign -type {args.type} -pubkeytype image -prikey {args.prikey} -algo aes128 -wrapkey {args.wrapkey} -infile {args.infile} -outfile {final_output}" + cmd_attr

    if args.cert != None:
        cmd_final = cmd_final + cmd_cert 

    print(cmd_final)
    os.system(cmd_final)
    signed_output = "signed_" + args.infile

    # do append
    if args.ddr_fw == None:
        args.ddr_fw = ""
    if args.scrtu_fw == None:
        args.scrtu_fw = ""

    cmd_append = f"cat {final_output} {args.scrtu_fw} {args.ddr_fw} > {signed_output}"
    print(cmd_append)
    os.system(cmd_append)
