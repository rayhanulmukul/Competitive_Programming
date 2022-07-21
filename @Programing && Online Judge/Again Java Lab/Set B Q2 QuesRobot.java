import java.awt.*;

class Robot{
    int direction = 0;
    Point loc = new Point(2, 2);
    String[] dr = {"N", "E", "S", "W"};
    public void turnLeft(){
        direction--;
        if(direction < 0) direction += 4;
    }
    public void turnRight(){
        direction++;
        direction %= 4;
    }
    public void move(){
        if(direction == 0) loc.y++;
        else if(direction == 1) loc.x++;
        else if(direction == 2) loc.y--;
        else if(direction == 3) loc.x--;
    }
    public Point getLocation(){
        return loc;
    }
    public String getDirection(){
        return dr[direction];
    }
}
public class QuesRobot {
    public static void main(String[] args) {
        Robot ap = new Robot();
        ap.turnLeft();
        ap.move();
        Point po = ap.getLocation();
        System.out.println("Robot Face move : " + ap.getDirection());
        System.out.println("Direction : "+po.x + " " + po.y);
    }
}
