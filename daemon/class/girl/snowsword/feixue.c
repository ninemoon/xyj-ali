// Update by waiwai@2002/12/05
// ��ѩ����

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	string str;
	int snowsword,moonforce,moondance,ini_damage_apply,times,damage;
	string desc_msg="";
	int sword_level;

	snowsword = (int)me->query_skill("snowsword", 1);
	moonforce = (int)me->query_skill("moonforce", 1);
	moondance = (int)me->query_skill("moondance", 1);
       
	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��˭ʩչ����ѩ���ǡ���\n");

	if(!me->is_fighting())
		return notify_fail("����ѩ���ǡ�ֻ����ս����ʹ�ã�\n");
	
	sword_level=(int)(snowsword/50);

	if( !wizardp(me) && userp(me) ) {

	if( snowsword < 60)
		return notify_fail("��ķ��ѩ�轣�����𻹲�����ʹ����һ�л������ѣ�\n");

	if( moonforce < 60)
		return notify_fail("���Բ���ķ���Ϊ������ʹ����һ�л������ѣ�\n");

	if( (int)me->query("can_perform/can_feixue") < 1 )
		return notify_fail(HIG"����δ�л�Ե�����ѩ���ǣ�����ʹ����һ�У�\n"NOR);

	if(me->query("family/family_name") != "�¹�")
		return notify_fail("[��ѩ����]���¹�����֮�ܣ�\n");

	if( me->query("force_factor") > 0)
		return notify_fail("����ѩ���ǡ��������в������������������ܽ������飿\n");

	if( me->query("force") < 600)
		return notify_fail("������������Դ߶�����ѩ���ǡ���������\n");

	if( moondance < 60)
		return notify_fail("������������輶�𻹲�����ʹ����һ�л������ѣ�\n");	
	
	if( time()-(int)me->query_temp("wuxue_end") < 10 )
		return notify_fail("�����ö�Ͳ����ˣ�\n");
	}

	if ( sword_level <= 1 ) desc_msg = "" ; else
		desc_msg = chinese_number(sword_level);
	if ( sword_level > 9 ) desc_msg = "��";
		ini_damage_apply = me->query_temp("apply/damage");
	
	message_vision(HIW"\n$N��߳һ�����ż�һ�㣬���弱���������ڰ����һ��������
ͬʱ�����ᶶ�������������������ѩ�����а�Ϯ��$n��\n"NOR,me,target);
	damage=1;
	//ǰ����
	message_vision(HIC"\n$Nͬʱʹ�����ѩ�轣��ǰ���У��ڰ����ѹ��$n��\n"NOR,me,target);
	
	me->add("force",-100);

	me->set_temp("WX_perform", 5);
	damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	if (damage < 1) me->add_temp("apply/damage",100);
	me->set_temp("WX_perform", 0);  
	damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
	
	if (damage < 1) {me->add_temp("apply/damage",100);}
		else    {me->set_temp("apply/damage",ini_damage_apply);}
	me->set_temp("WX_perform", 6);
	damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->start_busy(random(2));

	//������
	if( snowsword > 150 && moonforce > 150 && moondance > 150 ) {
		me->start_busy(1+random(2));
		me->add("force",-200);

	    	message_vision(HIC"\n$N����бб����Ʈ����Ҳ����ͷ�����־ʹ̳������С�\n"NOR,me);
		
		if (damage < 1) {me->add_temp("apply/damage",100);}
		    else    {me->set_temp("apply/damage",ini_damage_apply);}
		me->set_temp("WX_perform", 7);
		damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	     
		if (damage < 1) {me->add_temp("apply/damage",100);}
		    else    {me->set_temp("apply/damage",ini_damage_apply);}
		me->set_temp("WX_perform", 8);
		damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	      }
      
	   //�������
	   if( snowsword > 200 && moonforce > 200 && moondance > 200 ) {
		me->start_busy(random(2));
		me->add("force",-300);

	       	    message_vision(HIC"\n$Nббһ�ٸ���������������ǧ��֧����������һ�ɺ�������$n��\n"NOR,me,target);
	       	    
       	    if (damage < 1) {me->add_temp("apply/damage",100);}
			 else    {me->set_temp("apply/damage",ini_damage_apply);}
		    me->set_temp("WX_perform", 9);
		    damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      
		     if (damage < 1) {me->add_temp("apply/damage",300);}
			 else    {me->set_temp("apply/damage",ini_damage_apply);}
		    me->set_temp("WX_perform", 10);
		    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		if( userp(target) ) {	    
		     if (target->query("eff_kee")<0 || !living(target)) {
			str=target->name()+"��"+me->name()+"���¹����С�"HIR"��ѩ����"HIG"��ɱ���ˡ���˵ʬ������"+
			desc_msg+"ʮ�����ɼ��ǵ��˺ۣ�";
			message("channel:rumor",HIG"����ѩ���ǩ�"+str+"\n"NOR,users());
		       }
			}
		  }
			
	me->delete_temp("WX_perform");
	me->set_temp("apply/damage",ini_damage_apply);

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}

	me->set_temp("wuxue_end",time());
	return 1;
}
