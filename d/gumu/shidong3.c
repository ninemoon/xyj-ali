// ALi by NewX

inherit ROOM;

void create ()
{
    set("short", "ʯ��");
    set("long", @LONG

һ��������ʯ������������ͷ������ڶ����ģ���Լ����һЩ��ֵ�
����������Ӱ�´µģ���ԼƮ��һ����������
LONG);

    set("exits", ([ /* sizeof() == 3 */
        "north" : __DIR__"shidong4",
        "south" : __DIR__"shidong2",
        "east" : __DIR__"tiaojiaoroom",
        "west" : __DIR__"enjoyroom",
    ]));

  setup();
}

