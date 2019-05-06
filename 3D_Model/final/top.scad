
translate([80, -210, 0])  rotate([90, 0, 180])  
//translate([0, 0, 0])  rotate([0, 0, 0])  
difference() {
union(){
difference() {
    union()
    {
        rotate([0, 0, 0])  translate([10, 10, 0]) cube([60,60,200]);
        rotate([0, 0, 0])  translate([10, 0, 0]) cube([60,10,200]);
        rotate([0, 0, 0])  translate([0, 10, 0]) cube([10,60,200]);
        rotate([0, 0, 0])  translate([10, 70, 0]) cube([60,10,200]);
        rotate([0, 0, 0])  translate([70, 10, 0]) cube([10,60,200]);
        rotate([0, 0, 0])  translate([10, 10, 0]) cylinder(200,10,10,$fn=100);
        rotate([0, 0, 0])  translate([10, 70, 0]) cylinder(200,10,10,$fn=100);
        rotate([0, 0, 0])  translate([70, 10, 0]) cylinder(200,10,10,$fn=100);
        rotate([0, 0, 0])  translate([70, 70, 0]) cylinder(200,10,10,$fn=100);
    }
    rotate([0, 0, 0])  translate([15, 15, -1]) cube([50,50,202]);
    rotate([0, 0, 0])  translate([-1, 35, -1]) cube([82,80,202]);
    rotate([0, 0, 0])  translate([22.5, -1, 82.5]) cube([35,17,35]);
    rotate([0, 0, 0])  translate([20, -1, 80]) cube([40,3.5,40]);
    rotate([0, 0, 0])  translate([40, 16, 70]) 
    rotate([90, 0, 0]) cylinder(17,5,5,$fn=100);
    rotate([0, 0, 0])  translate([40, 16, 130]) 
    rotate([90, 0, 0]) cylinder(17,5,5,$fn=100);
}
rotate([0, 0, 0])  translate([15, 15, 177]) cube([50,25,20]);

rotate([0, 0, 0])  translate([65, 35, 0]) cube([15,10,200]);
rotate([0, 0, 0])  translate([0, 35, 0]) cube([15,10,200]);

rotate([0, 0, 0])  translate([15, 15, 18]) cube([50,10,5]);


}
    rotate([0, 0, 0])  translate([15, 15, -1]) cylinder(202,6,6,$fn=100);
    rotate([0, 0, 0])  translate([65, 15, -1])  cylinder(202,6,6,$fn=100);


rotate([0, 0, 0])  translate([19, 72.5, 190]) 
    rotate([90, 0, 0]) cylinder(65,10,10,$fn=100);
rotate([0, 0, 0])  translate([40, 72.5, 190]) 
    rotate([90, 0, 0]) cylinder(65,10,10,$fn=100);
rotate([0, 0, 0])  translate([61, 72.5, 190]) 
    rotate([90, 0, 0]) cylinder(65,10,10,$fn=100);
rotate([0, 0, 0])  translate([9, 47.5, 190]) 
    rotate([90, 0, 0]) cube([62,15,40]);

rotate([0, 0, 0])  translate([69.5, 35, -1]) cube([6,11,202]);
rotate([0, 0, 0])  translate([4.5, 35, -1]) cube([6,11,202]);
rotate([0, 0, 0])  translate([9, 5.5, 183]) cube([62,2,20]);
rotate([0, 0, 0])  translate([20, 7.5, 183]) cube([40,65,10]);

rotate([0, 0, 0])  translate([9, 15, 23]) cube([7,35,154]);
rotate([0, 0, 0])  translate([64, 15, 23]) cube([7,35,154]);
rotate([0, 0, 0])  translate([9, 15, -1]) cube([7,40,19]);
rotate([0, 0, 0])  translate([64, 15, -1]) cube([7,40,19]);
rotate([0, 0, 0])  translate([9, 25, -1]) cube([7,21,25]);
rotate([0, 0, 0])  translate([64, 25, -1]) cube([7,21,25]);

rotate([0, 0, 0])  translate([9, 40, 170]) cube([7,21,25]);
rotate([0, 0, 0])  translate([64, 40, 170]) cube([7,21,25]);


rotate([0, 0, 0])  translate([30, 25, 170]) 
rotate([0, 0, 0]) cylinder(30,2.5,2.5,$fn=100);
    
rotate([0, 0, 0])  translate([50, 25, 170]) 
 rotate([0, 0, 0]) cylinder(30,2.5,2.5,$fn=100);
    
    
    rotate([0, 0, 0])  translate([19, 9,-1]) cube([42,62,19]);
    rotate([0, 0, 0])  translate([15, 9,-1]) cube([50,30,19]);
   //
}












