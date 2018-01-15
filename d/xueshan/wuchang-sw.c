
//wuchang-sw.c

inherit ROOM;

void create ()
{
   set ("short", "西南武场");
   set ("long", @LONG

这是冰谷中的一块平地，供大雪山弟子练功之用。冰面极平，光
鉴照人。不过走在上面得小心点，雪山弟子也正是借此锻炼下盘
的稳固功夫。
LONG);

   set("exits", ([ //sizeof() == 3
     "north" : __DIR__"wuchang-w",
     "east" : __DIR__"wuchang-s",
   ]));

   set("outdoors", "xueshan");

   setup();
}
