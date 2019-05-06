translate([10,10, 0]) rotate([0, 0, 0])  
union()
{
difference() {
union()
{
rotate([0, 0, 0])  translate([0,0, 0]) cylinder(25,4,4,$fn=50);
rotate([0, 0, 0])  translate([0,0, 0]) cylinder(3,6,6,$fn=50);
    
 rotate([0, 0, 0])  translate([0,0, 25]) sphere(4,$fn=50);
}
rotate([0, 0, 0])  translate([0,0, -1]) cylinder(8,2.5,2.5,$fn=50);
}
}


union()
{
translate([30,10, 0]) rotate([0, 0, 0])  
difference() {
union()
{
rotate([0, 0, 0])  translate([0,0, 0]) cylinder(25,4,4,$fn=50);
rotate([0, 0, 0])  translate([0,0, 0]) cylinder(3,6,6,$fn=50);
    
 rotate([0, 0, 0])  translate([0,0, 25]) sphere(4,$fn=50);
}
rotate([0, 0, 0])  translate([0,0, -1]) cylinder(8,2.5,2.5,$fn=50);
}
}