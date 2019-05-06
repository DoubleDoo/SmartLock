translate([100, -30, 10])rotate([0, 0, 0])
union(){

difference() {
union()
{
     translate([-2.5, 0, 0])rotate([0, 0, 0]) 
     union()
     {
     rotate([180, 0, 0])  translate([10, 0, 0])        difference() {
rotate_extrude(angle=360, convexity=15) translate([20, 0]) circle(7.5);
     translate([-50, 0, -10]) cube([200,50,20]); 
    translate([-50, -50, -10]) cube([50,60,20]); 
}
     }  
     translate([-57.5, 0, 0])rotate([0, 180, 0])  
     union()
     {
      rotate([180, 0, 0])  translate([10, 0, 0])            difference() {
rotate_extrude(angle=360, convexity=15) translate([20, 0]) circle(7.5);
     translate([-50, 0, -10]) cube([200,50,20]); 
    translate([-50, -50, -10]) cube([50,60,20]); 
}
     }
 
     rotate([90, 0, 0])  translate([27.5, 0, 0]) cylinder(85,7.5,7.5,$fn=100);
     rotate([90, 0, 0])  translate([-87.5, 0, 0]) cylinder(85,7.5,7.5,$fn=100);
     rotate([0, 90, 0])       translate([0, 20, -67.5]) cylinder(75,7.5,7.5,$fn=100); 
}
     translate([-100, -70, -3.5]) cube([200,12,7]); 
}
}


