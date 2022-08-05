public static class pair implements Comparable<pair> , Comparator<pair>{
    int x; int y;
    public int compareTo(pair b){
        if(this.x == b.x){
            return (this.y < b.y)?1:0;
        }
        return (this.x < this.y)?1:0;
    }
    pair(int a, int b){
        this.x = a;
        this.y = b;
    }
    @Override
    public int compare(Main.pair o1, Main.pair o2) {
        if(o1.x == o2.x) return (o1.y < o2.y)?1:0;
        return (o1.x < o2.x)?1:0;
    }
    @Override
    public String toString(){
        return String.format(x + " " + y);
    }
}
