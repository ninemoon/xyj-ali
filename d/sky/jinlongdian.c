// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "金龙殿");
    set("long", @LONG

外厢犹可，入内惊人：里壁厢有几根大柱，柱上缠绕着金鳞耀日赤须龙；
威风凛凛，气势非凡。
LONG);

    set("exits", ([ /* sizeof() == 3 */
        "west" : __DIR__"jieyindian",
    ]));
    setup();
}

