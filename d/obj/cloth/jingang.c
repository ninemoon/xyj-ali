// ALi by NewX

#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
    set_name(HIR "金刚拳套" NOR, ({ "wrists" }));
    set_weight(800);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "只");
        set("material", "copper");
        set("value", 100);
        set("armor_prop/armor", 2);
    }
    setup();
}

