inherit ROOM;

void create()
{
    set("short", "百花窖");
    set("long", @LONG

一间密不透风的窑洞，这里就是百花仙子酿酒的所在了。

LONG);
    set("exits", ([
        "west" : __DIR__"hongyandong",
    ]));
    set("objects", ([
        __DIR__"obj/baihuaniang" : 1,
    ]));
    setup();
}
