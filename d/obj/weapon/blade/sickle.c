// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// sickle.c

#include <weapon.h>

inherit BLADE;

void create()
{
   set_name("����", ({ "sickle", "dao", "blade", "lian", "lian dao" }) );
   set_weight(1500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 200);
     set("material", "wood");
     set("long", "����һ��ũ���г�����������\n");
     set("wield_msg", "$N���һ��$n�������У������ϻ����ŵ��ݡ�\n");
     set("unequip_msg", "$N�����е�$n��������\n");
   }
   init_blade(5);
   setup();
}