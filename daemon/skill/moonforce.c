// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// moonforce.c  【太阴心经】
inherit FORCE;

string name() { return "太阴心经"; }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
    return CLASS_D("moon") + "/moonforce/" + func;
}

