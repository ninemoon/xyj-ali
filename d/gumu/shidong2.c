// ALi by NewX

inherit ROOM;

void create ()
{
    set("short", "ʯ��");
    set("long", @LONG

һ��������ʯ������������ͷ��������һ��С�ң���Լ����һЩ��ֵ�
������
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"shidong3",
        "south" : __DIR__"shidong1",
        "east" : __DIR__"practiceroom",
    ]));

  setup();
}

