-- bash <(curl -fsSL https://raw.githubusercontent.com/tboox/xmake/master/scripts/get.sh)

-- 编译 xmake
-- 服务器执行 xmake run udp-server
-- 客户端执行 xmake run udp-client 127.0.0.1

if is_host("macosx") then
    myhost="Darwin"
elseif is_host("linux") then
    myhost="Linux"
end


-- 客户端配置
target "getifiinfo"
    set_kind "binary"
    add_files "getifiinfo.c"
    add_includedirs("../libunp/include/"..myhost)
    add_links("unp")
    add_linkdirs("../libunp/lib/"..myhost)
