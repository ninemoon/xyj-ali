// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "白虎大街");
        set ("long", @LONG

这里已是白虎大街的西段，城门已经遥遥在望。北面是一座军营，远
远就能感到一阵肃杀气氛。南面则是一条阴暗的小巷，其中行人都是
低头快步而过，透出一阵诡异的气氛。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"beiyin1",
                "north" : "/d/jjf/yingzhai",
                "west" : __DIR__"ximen",
                "east" : __DIR__"baihu-w3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



