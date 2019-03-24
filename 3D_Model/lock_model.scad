
module model()
{
    union()
    {
    difference() {
    union()
    {
        rotate([0, 0, 0])  translate([0, 5, 0])  cube([27,15,17],false);
        rotate([0, 0, 0])  translate([0, 0, 0])  cube([27,25,1],false);
       translate([0, 0, 3]) difference() {
         rotate([0, 0, 0])  translate([-7, 10, 0])  cube([27,5,10],false);
         rotate([0, 35, 0])  translate([-16, 9, -5])  cube([10,7,15],false);
        }
    }
       rotate([0, 0, 0])  translate([2.5, 2.5, -5])  cylinder(10, 1.5, $fn=100);
       rotate([0, 0, 0])  translate([24.5, 2.5, -5])  cylinder(10, 1.5, $fn=100);
       rotate([0, 0, 0])  translate([2.5, 22.5, -5])  cylinder(10, 1.5, $fn=100);
       rotate([0, 0, 0])  translate([24.5, 22.5, -5])  cylinder(10, 1.5, $fn=100);
}
}
}


translate([0,0,0])model();
   