//bottom part
union(){
rotate([0, 0, 0])  translate([50, -100, 0]) 
difference() {
    union(){
        rotate([0, 0, 0])  translate([10, 10, 0]) cube([60,60,3]);
        rotate([0, 0, 0])  translate([10, 0, 0]) cube([60,10,3]);
        rotate([0, 0, 0])  translate([0, 10, 0]) cube([10,60,3]);
        rotate([0, 0, 0])  translate([10, 70, 0]) cube([60,10,3]);
        rotate([0, 0, 0])  translate([70, 10, 0]) cube([10,60,3]);
        rotate([0, 0, 0])  translate([10, 10, 0]) cylinder(3,10,10,$fn=100);
        rotate([0, 0, 0])  translate([10, 70, 0]) cylinder(3,10,10,$fn=100);
        rotate([0, 0, 0])  translate([70, 10, 0]) cylinder(3,10,10,$fn=100);
        rotate([0, 0, 0])  translate([70, 70, 0]) cylinder(3,10,10,$fn=100);
    }
    rotate([90, 0, 0])  translate([35.5,-3, -80+38]) cube([9,11,4]); 
    rotate([0, 0, 0])  translate([6, 6, -1]) cylinder(7,1.5,1.5,$fn=100);
    rotate([0, 0, 0])  translate([74, 6, -1]) cylinder(7,1.5,1.5,$fn=100);
    rotate([0, 0, 0])  translate([40, 2.75, -1]) cylinder(7,1.5,1.5,$fn=100);
    
    rotate([0, 0, 0])  translate([6, 74, -1]) cylinder(7,1.5,1.5,$fn=100);
    rotate([0, 0, 0])  translate([74, 74, -1]) cylinder(7,1.5,1.5,$fn=100);
    rotate([0, 0, 0])  translate([40, 77.25, -1]) cylinder(7,1.5,1.5,$fn=100);
}
}