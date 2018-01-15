// ALi by NewX

inherit ROOM;

void create ()
{
    set("short", "山外小路");
    set("long", @LONG

你突然到了火焰山的西北面，东南面是红通通的火焰山顶。空气中
有一种强烈的糊味，热得让人难以忍受。北方有一条小径，通向山
下阴凉处。

LONG);

    set("exits", ([
        "northdown"  : __DIR__"hongyan",
        "southeast"  : __DIR__"huoyan",
        ]));
    set("outdoors", "firemount");

    setup();
}

void init()
{
    add_action("do_all", "", 1);
}

int do_all(string arg)
{
    if (this_player()->query("obstacle/firemount")=="done")
        set("exits/southeast", __DIR__"nofire");
    else
        set("exits/southeast", __DIR__"huoyan");
    return 0;
}
