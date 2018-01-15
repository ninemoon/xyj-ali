// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "天宫大道");
    set("long", @LONG

一条大道，笔直的伸展出去，直通南天门。道上不时走过几名
巡查的天兵，持刀悬剑，威风凛凛。

LONG);

    set("exits", ([ /* sizeof() == 3 */
        "north" : __DIR__"dadao3",
        "south" : __DIR__"dadao1",
    ]));

    set("outdoors", 1);
    setup();
}

