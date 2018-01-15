
//wuchang-e.c

inherit ROOM;

void create ()
{
   set ("short", "东武场");
   set ("long", @LONG

这是冰谷中的一块平地，供大雪山弟子练功之用。冰面极平，光
鉴照人。不过走在上面得小心点，雪山弟子也正是借此锻炼下盘
的稳固功夫。
LONG);

   set("exits", ([ //sizeof() == 3
     "south" : __DIR__"wuchang-se",
     "north" : __DIR__"wuchang-ne",
     "west" : __DIR__"wuchang-c",
   ]));

   set("objects", ([ //sizeof() == 1
     __DIR__"npc/huanghe-shier" : 1,
   ]));

   set("outdoors", "xueshan");

   setup();
}

