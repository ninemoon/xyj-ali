// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
   set ("short", "望仙台");
   set ("long", @LONG

望仙台上乃是青红板石铺就，布局巧妙，隐有太极之意。台中放
一尺高铜炉，炉上小口中淡吐紫烟。台周有尺高护栏，皆雕龙刻
凤。远望山下，但见山若伏兽，水若游龙，宛尔有出世之意。
LONG);

   set("exits", 
   ([ //sizeof() == 4
     "northdown" : __DIR__"westway1",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/qingfeng" : 1,
     __DIR__"npc/xiaodaoshi" : 1,
   ]));


   set("outdoors", "wuzhuang");

   setup();
}
