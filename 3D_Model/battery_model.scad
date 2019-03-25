fn=50;

module battery_model()
{
    rotate([90, 0, 0])  union()
    {
        rotate([0, 0, 0])  translate([0, 0, 0])  cylinder(66, 9,9, $fn=fn);
        rotate([0, 0, 0])  translate([0, 0, -0.5])  cylinder(0.5, 4.5,4.5, $fn=fn);
    }
}

translate([0,0,0])battery_model();
   