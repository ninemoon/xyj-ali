// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "彩虹桥");
    set("long", @LONG

又有几座长桥，桥上跨着几道七色彩虹。这天上有三十三座天宫，
乃遣云宫、毗沙宫、五明宫、太阳宫、花药宫、……一宫宫脊吞
金稳兽；又有七十二重宝殿，乃朝会殿、凌虚殿、宝光殿、天王
殿、灵官殿、…… 一殿殿柱列玉麒麟。

LONG);

    set("exits", ([ /* sizeof() == 3 */
        "south" : __DIR__"jieyindian",
        "north" : __DIR__"xingrigong",
    ]));
    setup();
}

