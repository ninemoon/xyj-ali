// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
        set ("short", "����С��");
        set ("long", @LONG

��������Ӱ�����������㡣��Ȼֻ�Ƕ̶̵�һ���������������
�������������ס�������������ˮ����ӳ��������һƬ������
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"linyin1",
                "northup" : __DIR__"gate",
                //"west" : __DIR__"binggu",
//                "east" : __DIR__"pool",
                //"up" : __DIR__"***",
                //"down" : __DIR__"***",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                //__DIR__"npc/***" : 1,
        ]));


        set("outdoors", "wuzhuang");

        setup();
}
