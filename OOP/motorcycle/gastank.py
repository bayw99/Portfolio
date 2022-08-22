class Gas :
    DEFAULT_TANK : float = 4.5
    DEFAULT_GALLONS : float = 4.5 
    TOTAL_MILES : float = 225

    def __init__(self, tanksize : float = DEFAULT_TANK, gallons : float = DEFAULT_GALLONS):
        self._tanksize = tanksize
        self._gallons = gallons
        self._miles : bool = False

    @property
    def tanksize(self) -> float:
        return self._tanksize
    
    @property
    def gallons(self) -> float:
        return self._gallons

    @gallons.setter
    def miles(self,value : float) -> None:
        if value < 0:
            raise ValueError(f"miles {value} must be non-negative")
        if value >= self.TOTAL_MILES:
            self._miles = True
        if self._miles:
            value = 0.0
        self._gallons = value

    @property
    def empty(self) -> bool:
        return self._gallons == 0.0

    
