//standroom.c used by weiqi...others may hate this format:D
//xueshan1.c

inherit ROOM;

void create ()
{
  set ("short", "茫茫雪峰");
  set ("long", @LONG

北风呼啸，飞雪茫茫。西北两面望去均是绵延不尽的雪峰，再往前走便要
将生迹抛在身后了。东南方向亦是群山起伏，只是冰雪已部分消融，要走
出大雪山是成功在望了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
    "south" : "/d/moon/kunlun",
    "north" : __DIR__"xueshan2",
  ]));

  set("outdoors", "xueshan");
  setup();
}


