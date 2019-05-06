

//bottom part
rotate([0, 0, 0])  translate([200, -100, 0]) 
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
    rotate([0, 0, 0])  translate([10, 40, -1]) cylinder(7,1.5,1.5,$fn=100);
    rotate([0, 0, 0])  translate([70, 20, -1]) cylinder(7,1.5,1.5,$fn=100);
    rotate([0, 0, 0])  translate([70, 60, -1]) cylinder(7,1.5,1.5,$fn=100);
}


