"""
Given n points on a 2D plane, find the maximum number of points that lie on 
the same straight line.

"""
class Point:
    def __init__(self, a, b):
        self.x = a
        self.y = b

def main():
    p0 = Point(0,0)
    p1 = Point(0,1)
    p2 = Point(0,2)
    p3 = Point(1,1)
    p4 = Point(2,2)
    p5 = Point(3,3)
    p6 = Point(4,4)
    p7 = Point(5,0)
    
    points = [p0,p1,p2,p3,p4,p5,p6,p7]
    
    result = points_line(points)
    print result

def points_line(points):
    if len(points) <= 2:
        return len(points)
    
    max_points = -1

    for point in points:
        cur_points = 1
        same_points = -1
        slope = dict()
        for other in points:
            #same points
            if point.x == other.x and point.y == other.y:
                same_points += 1
            else:
                #90 degree
                if point.x == other.x:
                    k = float("inf")
                else:
                    k = 1.0*(point.y-other.y)/(point.x-other.x)
                #check mapping
                if k in slope:
                    slope[k] += 1
                else:
                    slope[k] = 2
                cur_points = max(cur_points, slope[k])
        cur_points += same_points
        max_points = max(cur_points, max_points)
        print "cur ", cur_points
    
    return max_points

if __name__ == "__main__":
    main()  