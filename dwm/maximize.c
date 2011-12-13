void
maximize(unsigned int s) {
	Client *c;
	
	domwfact[s] = dozoom[s] = False;        
        for(c = clients; c; c = c->next)
		if (c->screen == s)
			if (isvisible(c)) {
				unban(c);
				if(! c->isfloating)
					resize(c, wax[s], way[s], waw[s] - 2 * BORDERPX, wah[s] - 2 * BORDERPX, True);
			} else {
				ban(c);
			}
	
        focus(NULL);
        restack();
}

