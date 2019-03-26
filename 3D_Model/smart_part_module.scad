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


module locker_model()
{
    union()
    {
        difference() 
        {
            union()
            {
                 rotate([0, 0, 0])  translate([0, 5, 0])  cube([27,15,17],false);
                 rotate([0, 0, 0])  translate([0, 0, 0])  cube([27,25,1],false);
                 translate([0, 0, 3]) 
                 difference() 
                 {
                     rotate([0, 0, 0])  translate([-7, 10, 0])  cube([27,5,10],false);
                     rotate([0, 35, 0])  translate([-16, 9, -5])  cube([10,7,15],false);
                }
            }
           rotate([0, 0, 0])  translate([2.5, 2.5, -5])  cylinder(10, whole_radius, $fn=fn);
           rotate([0, 0, 0])  translate([24.5, 2.5, -5])  cylinder(10, whole_radius, $fn=fn);
           rotate([0, 0, 0])  translate([2.5, 22.5, -5])  cylinder(10, whole_radius, $fn=fn);
           rotate([0, 0, 0])  translate([24.5, 22.5, -5])  cylinder(10, whole_radius, $fn=fn);
        }
    }
}

module smart_part_model()
{
    difference() 
        {
    union()
            {
                
               rotate([0, 0, 0])  translate([-5, -5, 0])  cube([190,60,10],false);
              // rotate([90, 0, 0])  translate([-5, -55, 0])  cube([190,60,10],false);
                // rotate([-90, 0, 0])  translate([-5, -5, 50])  cube([190,60,10],false);
                 rotate([180, 0, 0])  translate([-5, -55, 50])  cube([190,60,10],false);
                 rotate([0, 90, 0])  translate([-5, -5, -5])  cylinder(190, 5, 5,$fn=fn);
                 rotate([0, 90, 0])  translate([-5, 55, -5])  cylinder(190, 5, 5, $fn=fn);
                 rotate([0, 90, 0])  translate([55, -5, -5])  cylinder(190,5, 5, $fn=fn);
                 rotate([0, 90, 0])  translate([55, 55, -5])  cylinder(190, 5, 5,$fn=fn);
                rotate([0, 0, 0])  translate([0, 12.5, -25])  cube([30,25,25],false);
                rotate([0, 0, 0])  translate([150, 12.5, -25])  cube([30,25,25],false);
                rotate([0, 0, 0])  translate([60, 25, -5])  cylinder(10, 5, 5,$fn=fn);
              rotate([0, 0, 0])  translate([120, 25, -5])  cylinder(10, 5, 5,$fn=fn);
              rotate([0, 0, 0])  translate([145, 5, -7.5])  cylinder(15, whole_radius+2.5, whole_radius+2.5,$fn=fn);
              rotate([0, 0, 0])  translate([145, 45, -7.5])  cylinder(15, whole_radius+2.5, whole_radius+2.5,$fn=fn);
              rotate([0, 0, 0])  translate([35, 5, -7.5])  cylinder(15,whole_radius+2.5, whole_radius+2.5,$fn=fn);
              rotate([0, 0, 0])  translate([35, 45, -7.5])  cylinder(15, whole_radius+2.5, whole_radius+2.5,$fn=fn);
                
              rotate([0, 0, 0])  translate([-10, -5,-55 ])  cube([10,60,60],false);
                 rotate([0, 0, 0])  translate([180,-5,-55 ])  cube([10,60,60],false);
                 rotate([0, 0, 0])  translate([-5, -5, -55])  cylinder(60, 5, 5,$fn=fn);
                 rotate([0, 0, 0])  translate([-5, 55, -55])  cylinder(60, 5, 5, $fn=fn);
                 rotate([0, 0, 0])  translate([185, -5, -55])  cylinder(60,5, 5, $fn=fn);
                 rotate([0, 0, 0])  translate([185, 55, -55])  cylinder(60, 5, 5,$fn=fn);
                 rotate([90, 0, 0])  translate([-5, -55, -55])  cylinder(60, 5, 5,$fn=fn);
                 rotate([90, 0, 0])  translate([-5, 5, -55])  cylinder(60, 5, 5, $fn=fn);
                 rotate([90, 0, 0])  translate([185, -55, -55])  cylinder(60,5, 5, $fn=fn);
                 rotate([90, 0, 0])  translate([185, 5, -55])  cylinder(60, 5, 5,$fn=fn);
                  rotate([0, 0, 0])  translate([-5, -5, 5]) sphere(5,$fn=fn);
                  rotate([0, 0, 0])  translate([-5, 55, 5]) sphere(5,$fn=fn);
                  rotate([0, 0, 0])  translate([-5, -5, -55]) sphere(5,$fn=fn);
                  rotate([0, 0, 0])  translate([-5, 55, -55]) sphere(5,$fn=fn);
                  rotate([0, 0, 0])  translate([185, -5, 5]) sphere(5,$fn=fn);
                  rotate([0, 0, 0])  translate([185, 55, 5]) sphere(5,$fn=fn);
                  rotate([0, 0, 0])  translate([185, -5, -55]) sphere(5,$fn=fn);
                  rotate([0, 0, 0])  translate([185, 55, -55]) sphere(5,$fn=fn);
            }
              rotate([0, 0, 0])  translate([40, 25, -65])  cylinder(20, 10+2*delta, 10+2*delta,$fn=fn);
              rotate([0, 0, 0])  translate([140, 25, -65])  cylinder(20, 10+2*delta, 10+2*delta,$fn=fn);
              rotate([0, 0, 0])  translate([60, 25, -10])  cylinder(21, 2.5, 2.5,$fn=fn);
              rotate([0, 0, 0])  translate([120, 25, -10])  cylinder(21, 2.5, 2.5,$fn=fn);
             rotate([0, 0, 0])  translate([70, 15, -5])  cube([40,20,20],false);
              rotate([0, 0, 0])  translate([145, 5, -8])  cylinder(16, whole_radius, whole_radius,$fn=fn);
              rotate([0, 0, 0])  translate([145, 45, -8])  cylinder(16, whole_radius, whole_radius,$fn=fn);
              rotate([0, 0, 0])  translate([35, 5, -8])  cylinder(16,whole_radius, whole_radius,$fn=fn);
              rotate([0, 0, 0])  translate([35, 45, -8])  cylinder(16, whole_radius, whole_radius,$fn=fn);
             
        }
}




translate([-70,0,0]) 
{smart_part_model();
 rotate([-90, 0, 0])  translate([90, 197.5, 25]) model();
 rotate([0, 180, 0]) translate([-30,12.5,25])locker_model();
 rotate([0, 180, 180]) translate([150,-37.5,25])locker_model();
 //rotate([0, 0, 0])  translate([30, 1, -11])  cube([120,48,3],false);
}
   