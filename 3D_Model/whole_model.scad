

module U()
{
    union()
    {
        for(i=[0:180]) 
        rotate([90, 0, i])  translate([50, 0, 0]) cylinder(3,10,10,$fn=100);
        rotate([90, 0, 0])  translate([50, 0, 0]) cylinder(150,10,10,$fn=100);
        rotate([90, 0, 0])  translate([-50, 0, 0]) cylinder(150,10,10,$fn=100);
        rotate([90, 0, 0])  translate([50, 0, 0]) cylinder(180,5,5,$fn=100);
        rotate([90, 0, 0])  translate([-50, 0, 0]) cylinder(180,5,5,$fn=100);
        rotate([90, 0, 0])  translate([50, 0, 170]) cylinder(10,10,10,$fn=100);
        rotate([90, 0, 0])  translate([-50, 0, 170]) cylinder(10,10,10,$fn=100);
    }
    
    difference() {

}
    cube([15,5,10],false);
}


translate([0,0,0])U();

module ring(
        h=1,
        od = 10,
        id = 5,
        de = 0.1
        ) 
{
    difference() {
        cylinder(h=h, r=od/2);
        translate([0, 0, -de])
            cylinder(h=h+2*de, r=id/2);
    }
}