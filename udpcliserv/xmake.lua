-- bash <(curl -fsSL https://raw.githubusercontent.com/tboox/xmake/master/scripts/get.sh)

-- 编译 xmake
-- 服务器执行 xmake run udp-server
-- 客户端执行 xmake run udp-client 127.0.0.1

-- 客户端配置
target "udp-client"
    set_kind "binary"
    add_files "udp-client.c"
    add_includedirs("../libunp/include")
    add_links("unp")
    add_linkdirs("../libunp/lib")

-- 服务器配置
target "udp-server"
    set_kind "binary"
    add_files "udp-server.c"
    add_includedirs("../libunp/include")
    add_links("unp")
    add_linkdirs("../libunp/lib")
