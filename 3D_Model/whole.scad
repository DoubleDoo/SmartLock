

//bottom part
rotate([0, 0, 0])  translate([0, 0, -5]) 
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

//bottom part
rotate([0, 0, 0])  translate([0, 0, 205]) 
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
        rotate([0, 0, 0])  translate([6, 6, -1]) cylinder(7,1.5,1.5,$fn=100);
    rotate([0, 0, 0])  translate([74, 6, -1]) cylinder(7,1.5,1.5,$fn=100);
    rotate([0, 0, 0])  translate([40, 2.75, -1]) cylinder(7,1.5,1.5,$fn=100);
    
    rotate([0, 0, 0])  translate([6, 74, -1]) cylinder(7,1.5,1.5,$fn=100);
    rotate([0, 0, 0])  translate([74, 74, -1]) cylinder(7,1.5,1.5,$fn=100);
    rotate([0, 0, 0])  translate([40, 77.25, -1]) cylinder(7,1.5,1.5,$fn=100);
}



//face


//translate([80, -210, 0])  rotate([90, 0, 180])  
translate([0, -10, 0])  rotate([0, 0, 0])  
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

rotate([0, 0, 0])  translate([71, 36, -1]) cube([4.75,11,202]);
rotate([0, 0, 0])  translate([4.25, 36, -1]) cube([4.75,11,202]);//
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
 
 
 
 rotate([0, 0, 0])  translate([74, 6, 185]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([6, 6, 185]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);

rotate([0, 0, 0])  translate([40, 2.75, 185]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([40, 2.75, -1]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);

rotate([0, 0, 0])  translate([74, 6, -1]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([6, 6, -1]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);



rotate([0, 0, 0])  translate([22.5, 16, 27.5]) 
rotate([90, 0, 0]) cylinder(8,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([(80-22.5), 16, 27.5]) 
rotate([90, 0, 0]) cylinder(8,1.5,1.5,$fn=100);

rotate([0, 0, 0])  translate([22.5, 16, (200-27.5)]) 
rotate([90, 0, 0]) cylinder(8,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([(80-22.5), 16, (200-27.5)]) 
rotate([90, 0, 0]) cylinder(8,1.5,1.5,$fn=100);


rotate([0, 0, 0])  translate([22.5, 16, 27.5+25]) 
rotate([90, 0, 0]) cylinder(8,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([(80-22.5), 16, 27.5+25]) 
rotate([90, 0, 0]) cylinder(8,1.5,1.5,$fn=100);

rotate([0, 0, 0])  translate([22.5, 16, (200-27.5-25)]) 
rotate([90, 0, 0]) cylinder(8,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([(80-22.5), 16, (200-27.5-25)]) 
rotate([90, 0, 0]) cylinder(8,1.5,1.5,$fn=100);
    
    
    rotate([0, 0, 0])  translate([19, 9,-1]) cube([42,62,19]);
    rotate([0, 0, 0])  translate([15, 9,-1]) cube([50,30,19]);
   //
   
rotate([0, 0, 0])  translate([6.75, 36, 5]) 
rotate([90, 0, 0]) cylinder(6,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([80-6.75, 36, 5]) 
rotate([90, 0, 0]) cylinder(6,1.5,1.5,$fn=100);
}







//translate([90, -210, 80])  rotate([-90, 0, 0])

translate([0, 10, 0])  rotate([0, 0, 0])
difference() {
union(){

difference() {
    union(){
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
    rotate([0, 0, 0])  translate([-1, -35, -1]) cube([82,80,202]);
    
    rotate([0, 0, 0])  translate([40, 81, 42.5]) 
    rotate([90, 0, 0]) cylinder(17,8.5,8.5,$fn=100);
    rotate([0, 0, 0])  translate([40, 81, 157.5]) 
    rotate([90, 0, 0]) cylinder(17,8.5,8.5,$fn=100);
    //
  //   rotate([0, 0, 0])  translate([9, 5,-1]) cube([12,60,200]);
 //rotate([0, 0, 0])  translate([59, 5,-1]) cube([12,60,200]);
    //
}
rotate([0, 0, 0])  translate([15, 40, 177]) cube([50,25,20]);
rotate([0, 0, 0])  translate([65, 36, 0]) cube([15,10,200]);
rotate([0, 0, 0])  translate([0, 36, 0]) cube([15,10,200]);

rotate([0, 0, 0])  translate([15, 55, 18]) cube([50,10,5]);


}
    rotate([0, 0, 0])  translate([15, 65, -1]) cylinder(202,6,6,$fn=100);
    rotate([0, 0, 0])  translate([65, 65, -1]) cylinder(202,6,6,$fn=100);

rotate([0, 0, 0])  translate([19, 72.5, 190]) 
    rotate([90, 0, 0]) cylinder(65,10,10,$fn=100);
rotate([0, 0, 0])  translate([40, 72.5, 190]) 
    rotate([90, 0, 0]) cylinder(65,10,10,$fn=100);
rotate([0, 0, 0])  translate([61, 72.5, 190]) 
    rotate([90, 0, 0]) cylinder(65,10,10,$fn=100);
rotate([0, 0, 0])  translate([9, 72.5, 190]) 
    rotate([90, 0, 0]) cube([62,60,40]);

rotate([0, 0, 0])  translate([64, 35, 23]) cube([7,30,154]);
rotate([0, 0, 0])  translate([-1, 34, -1]) cube([6,11,202]);
rotate([0, 0, 0])  translate([75, 34, -1]) cube([6,11,202]);
rotate([0, 0, 0])  translate([9, 35, 23]) cube([7,30,154]);
rotate([0, 0, 0])  translate([9, 34, -1]) cube([7,21,30]);
rotate([0, 0, 0])  translate([64, 34, -1]) cube([7,21,30]);
rotate([0, 0, 0])  translate([9, 35, -1]) cube([7,30,19]);
rotate([0, 0, 0])  translate([64, 35, -1]) cube([7,30,19]);

rotate([0, 0, 0])  translate([9, 10, 170]) cube([7,30,19]);
rotate([0, 0, 0])  translate([64, 10, 170]) cube([7,30,19]);

rotate([0, 0, 0])  translate([9, 72.5, 183]) cube([62,2,20]);

rotate([0, 0, 0])  translate([20, 7.5, 183]) cube([40,65,10]);
//

rotate([0, 0, 0])  translate([29.5, 55, 170]) 
rotate([0, 0, 0]) cylinder(30,2.5,2.5,$fn=100);
    
rotate([0, 0, 0])  translate([50.5, 55, 170]) 
rotate([0, 0, 0]) cylinder(30,2.5,2.5,$fn=100);





rotate([0, 0, 0])  translate([74, 74, 185]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([6, 74, 185]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);

rotate([0, 0, 0])  translate([40, 77.25, 185]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([40, 77.25, -1]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);

rotate([0, 0, 0])  translate([74, 74, -1]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);
rotate([0, 0, 0])  translate([6, 74, -1]) 
rotate([0, 0, 0]) cylinder(16,1.5,1.5,$fn=100);


rotate([0, 0, 0])  translate([19, 9,-1]) cube([42,62,19]);

 rotate([0, 0, 0])  translate([15, 41,-1]) cube([50,30,19]);
 
 rotate([0, 0, 0])  translate([15, 11,23]) cube([50,60,154]);
 
 rotate([0, 0, 0]) translate([0, 35, -1]) cube([80,10,12]); 

 //
}





translate([40, 120, 70])rotate([0, 90, 0])
//translate([360, -100, 10])rotate([0, 0, 0])
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
 
     rotate([90, 0, 0])  translate([27.5, 0, 0]) cylinder(75,7.5,7.5,$fn=100);
     rotate([90, 0, 0])  translate([-87.5, 0, 0]) cylinder(75,7.5,7.5,$fn=100);
     rotate([0, 90, 0])       translate([0, 20, -67.5]) cylinder(75,7.5,7.5,$fn=100); 
}
     translate([-100, -65, -3.5]) cube([200,12,7]); 
}

}


translate([40,10, 70]) rotate([90, 0, 0])  
difference() {
union()
{
rotate([0, 0, 0])  translate([0,0, 0]) cylinder(25,4,4,$fn=100);
rotate([0, 0, 0])  translate([0,0, 0]) cylinder(3,6,6,$fn=100);
    
 rotate([0, 0, 0])  translate([0,0, 25]) sphere(4,$fn=100);
}
rotate([0, 0, 0])  translate([0,0, -1]) cylinder(8,2.5,2.5,$fn=100);
}




translate([40,10, 130]) rotate([90, 0, 0])  
difference() {
union()
{
rotate([0, 0, 0])  translate([0,0, 0]) cylinder(25,4,4,$fn=100);
rotate([0, 0, 0])  translate([0,0, 0]) cylinder(3,6,6,$fn=100);
    
 rotate([0, 0, 0])  translate([0,0, 25]) sphere(4,$fn=100);
}
rotate([0, 0, 0])  translate([0,0, -1]) cylinder(8,2.5,2.5,$fn=100);
}


