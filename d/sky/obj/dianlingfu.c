// ALi by NewX

inherit ITEM;

void create()
{
    set_name("电灵符", ({"dian ling fu","fu"}));
    set("unit", "张");
    set_weight(10);
    set("long", "一张电母给的的灵符，需要闪电时，不妨试试看祭(ji)它。\n");
    set("no_give", "这种玩艺怎能随便给人？\n");
    set("no_sell", "掌柜的摇摇头说：这宝贝小店不敢收。\n");
    setup();
}

void init()
{
    add_action("do_ji", "ji");
}

int do_ji(string arg)
{
    object me = this_player();
    object env;
    
    if (!arg || !id(arg)) return notify_fail("你想祭什么？\n");

    if (me->query("mana") + random(500) < 1000) {
        message_vision("$N拿出电灵符，大喝一声：“闪电！”\n", me);
        message_vision("但什么也没有发生。”\n", me);
    } else {
        message_vision("$N拿出电灵符，大喝一声：“闪电！”\n", me);
        message_vision("顿时电光大作，耀眼夺魂！\n", me);
        message_vision("哇！好亮的闪电！\n", me);
        env = environment(me);
        env->weather_effect("light");
        foreach (object ob in all_inventory(env)) {
            if (ob) ob->weather_effect("light");
        }
    }
    destruct(this_object());
    return 1;
}
