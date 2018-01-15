// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit FORCE;

string name() { return "龙神心法"; }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
    if (me->query("class") != "dragon")
        return notify_fail("你非龙族怎能学龙神心法？\n");
    return 1;
}

string exert_function_file(string func)
{
    return CLASS_D("dragon") + "/dragonforce/" + func;
}

int practice_skill(object me)
{
    if (me->query("class") != "dragon")
        return notify_fail("你非龙族，再练有害无益。\n");
    
    if (!environment(me)->query("dragonforce_practice"))
        return notify_fail("龙神心法只能在特殊的法台上才可练。\n");

    if ((int)me->query_skill("dragonforce", 1) >= 200)
        return notify_fail("你的龙神心法很难提高了，还是向你师父请教请教吧！\n");

    if ((int)me->query_temp("dragonforce_practice") < 1)
        return notify_fail("你试着练功，可毫无进展，需要驯服更多的海兽以增进龙神心法。\n");

    if ((int)me->query("kee") < 30)
        return notify_fail("你的气不够。\n");
    if ((int)me->query("sen") < 30)
        return notify_fail("你的神不够。\n");
    if ((int)me->query("force") < 10)
        return notify_fail("你的内力不够");
    me->receive_damage("kee", 30);
    me->receive_damage("sen", 30);
    me->add("force", -10);
    me->add_temp("dragonforce_practice",-1);
    return 1;
}

void skill_improved(object me)
{
    string *names = ({"青龙","苍龙","赤龙","黄龙","黑龙","金龙","银龙","雪龙","火龙"});
    if ((int)me->query_skill("dragonforce", 1) >= 25 && me->query("class") != "dragon") {
        message_vision("$N身上忽然散发出一股惊人的气势，背后一条" + names[random(sizeof(names))]+ "的虚影浮现，周围的人不仅看得呆了。\n", me);
        tell_object(me, "恭喜！你获得了龙族的本质！\n");
        me->set("class", "dragon");
    }
}
