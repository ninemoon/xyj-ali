
//wuchang-s.c

inherit ROOM;

void create ()
{
   set ("short", "南武场");
   set ("long", @LONG

这是冰谷中的一块平地，供大雪山弟子练功之用。冰面极平，光
鉴照人。不过走在上面得小心点，雪山弟子也正是借此锻炼下盘
的稳固功夫。
LONG);

   set("exits", ([ //sizeof() == 4
     "south" : __DIR__"binggu",
     "north" : __DIR__"wuchang-c",
     "west" : __DIR__"wuchang-sw",
     "east" : __DIR__"wuchang-se",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));

   set("objects", ([ //sizeof() == 1
     __DIR__"npc/xunshi" : 2,
   ]));

   set("outdoors", "xueshan");

   setup();
}
