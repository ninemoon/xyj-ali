// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// echowhip.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
   set_name( HIM "ħ������" NOR, ({ "echo whip", "whip" }) );
   set_weight(17000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 10000);
     set("material", "leather");
     set("rigidity", 70);
     set("wield_msg", "$N���������һ��$n�������С�\n");
     set("unwield_msg", "$N�����е�$n�������䡣\n");
   }
   init_whip(53);
   setup();
}