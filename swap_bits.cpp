// 0xAAAAAA and 0x55555 are nubers with all even and all odd bits 1 respectively
// even and odd are seen after counting with zero index


unsigned int swapBits(unsigned int n)
{
	
	// Your code here
	unsigned int el,ro;
	el = n<<1;
	ro = n>>1;
	el = el & 0xAAAAAAAA;
	ro = ro & 0x55555555;
	return (el | ro);
	
}