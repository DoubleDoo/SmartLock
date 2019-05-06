whole_radius=1.5;
delta=0.25;
fn=50;

module PartOne()
{
 rotate([0, 180, 0])  translate([0, 0, 0]) PartTwo();
}

module PartTwo()
{
    union()
    {
        difference() 
        {
            rotate([90, 0, 0])  translate([50, 0, 0]) cylinder(180,10,10,$fn=fn);
            union()
            {
                translate([59, -170, 13.5]) rotate([90, 180, 180])
                difference() 
                {
                    rotate([0, 0, 0])  translate([-7, 10, 0])  cube([21,7,10],false);
                    rotate([0, 35, 0])  translate([-16, 9, -6])  cube([10,9,15],false);
                }
            }   
            rotate([0, 0, 0])  translate([50-delta, -30-delta, -10])  cube([20,36,25],false);  
            translate([-70, -5, 0])  rotate([0, 90, 0])cylinder(140,whole_radius,whole_radius,$fn=fn);
            translate([-70, -25, 0])  rotate([0, 90, 0])cylinder(140,whole_radius,whole_radius,$fn=fn); 
             rotate([90, 0, 0])  translate([50, 0, -1]) cylinder(1+delta*2,11,11,$fn=fn);
        }   
    }
}
module PartThree()
{
    union()
    {
        difference() 
        {
            union()
            {
                for(i=[0:90]) rotate([90, 0, 2*i])  translate([50, 0, 0]) cylinder(3,10,10,$fn=fn);
                rotate([90, 0, 0])  translate([50, 0, 0]) cylinder(30-delta,10,10,$fn=fn);
                rotate([90, 0, 0])  translate([-50, 0, 0]) cylinder(30-delta,10,10,$fn=fn);
            }
            rotate([0, 0, 0])  translate([30+delta, -35, -10])  cube([20,35,25],false);  
            rotate([0, 0, 0])  translate([-50-delta, -35, -10])  cube([20,35,25],false);  
            translate([-70, -5, 0])  rotate([0, 90, 0])cylinder(140,whole_radius,whole_radius,$fn=fn);
            translate([-70, -25, 0])  rotate([0, 90, 0])cylinder(140,whole_radius,whole_radius,$fn=fn); 
        }   
    }
}

module model()
{
     rotate([0, 0, 0])  translate([0, 0, 0])  PartThree();
     rotate([0, 0, 0])  translate([0, 0, 0]) PartTwo();
     rotate([0, 0, 0])  translate([0, 0, 0]) PartOne();
}

 rotate([0, 0, 0])  translate([0, 0, 0]) model();