// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "彩凤殿");
    set("long", @LONG

外厢犹可，入内惊人：里壁厢有几条彩羽凌空丹顶凤。明霞幌幌
映天光，碧雾蒙蒙遮斗口。

LONG);

    set("exits", ([ /* sizeof() == 3 */
        "east" : __DIR__"jieyindian",
    ]));
    setup();
}

