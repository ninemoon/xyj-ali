// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/qiang7f.c

inherit ROOM;

void create ()
{
  set ("short", "��ǽ");
  set ("long", @LONG

�ߴ�ĳ�ǽ�������ɶ�ߣ��ɻ��Ҽл������ɡ���ǽ�ϰ߲߰�����
�������Ѿ���Щ����ˣ����ų�����ǽ����һ����ʵ����ʯ·��
���������߳���

LONG);

  set("exits", ([
        "west"         : __DIR__"qiang7e",
        "east"         : __DIR__"qiang7g",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}
