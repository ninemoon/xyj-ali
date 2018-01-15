#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
    string msg;
    object weapon, weapon2;
    int skill, ap, dp, damage;

    if (!target) target = offensive_target(me);

    if (!target
    ||  !target->is_character()
    ||  target->is_corpse()
    ||  target==me)
    return notify_fail("你要以谁施展这一招「无尽风波」?\n");

    if (!(me->is_fighting()))
        return notify_fail(HIW"「无尽风波」"NOR+"只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
    ||  (string)weapon->query("skill_type") != "fork")
        return notify_fail("你使用的武器不对。\n");

    skill = me->query_skill("fengbo-cha",1);
    if (skill < 100)
        return notify_fail("你的风波十二叉等级不够, 不能使用「无尽风波」！\n");

    if (me->query("force") < 1000)
        return notify_fail("你的内力不够，无法运用「无尽风波」！\n");

    msg = HIC "$N凝神闭息,将手中"+weapon->name()+HIC"绕了几圈,猛地向$n的兵刃卷去。\n";
    message_vision(msg, me, target);

    damage = 10 + random(skill / 2);

    ap = me->query_skill("fork") +4*skill ;
    dp = target->query_skill("force") + 4;

    if (dp < 1)
        dp = 1;                        

    if (random(ap) > random(dp)) {
        // if(userp(me))
        me->add("force",-50);
        if (objectp(weapon2 = target->query_temp("weapon"))) {
            msg = "$n顿时觉得手臂一麻，手中"+weapon2->name()+"脱手而出！\n" NOR;
            message_vision(msg, me, target);
            weapon2->move(environment(me));
            return 1;
        }
        target->receive_damage("kee", damage);
        target->start_busy(4+random(skill)/20);
        msg = "谁知$n手中根本就没有武器，$N顿时破绽百出！\n";
        message_vision(msg, me, target);
        me->start_busy(1);
        return 1;
    }
    else {
        me->add("force",-30);
        if (objectp(weapon2 = target->query_temp("weapon"))){
            msg = "可是$n看破了$N的企图，立刻将手中" + weapon2->name()
                + "舞得风雨不透，使$N的「无尽风波」没有起到作用。\n"NOR;
            message_vision(msg, me, target);
            me->start_busy(2);
            return 1;
        }
        msg = "谁知$n手中根本就没有武器，$N顿时破绽百出！\n";
        message_vision(msg, me, target);
        me->start_busy(2);
        return 1;
    }

    return 1;
} 

