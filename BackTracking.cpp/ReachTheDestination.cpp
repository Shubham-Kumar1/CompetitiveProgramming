
bool reachDestination(int sx, int sy, int dx, int dy) {
    // Write your code here
    
	if(sx>dx || sy>dy) return false;
    if(sx==dx) return (dy-sy)%sx==0;
    if(sy==dy) return (dx-sx)%sy==0;
    
    if(dx > dy) return reachDestination(sx,sy,dx-dy,dy);
    else if(dy > dx) reachDestination(sx,sy,dx,dy-dx);
    else return false;
}
