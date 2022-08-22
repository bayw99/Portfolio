class Cup:
    OVER_AMOUNT : float = 5.0   
    DEFAULT_VOLUME : float = 5.0  # cups
    DEFAULT_AMOUNT : float = OVER_AMOUNT/1.25   

    def __init__(self, volume : float = DEFAULT_VOLUME, amount : float = DEFAULT_AMOUNT):
        self._volume = volume
        if amount < 0:
            raise ValueError(f"amount {amount} must be non-negative")
        self._amount = amount
        self._over : bool = False
        
    @property
    def volume(self) -> float:
        return self._volume
    
    @property
    def amount(self) -> float:
        return self._amount

    @amount.setter
    def amount(self,value : float) -> None:
        if value < 0:
            raise ValueError(f"amount {value} must be non-negative")
        if value >= self.OVER_AMOUNT:
            self._over = True
        if self._over:
            value = 0.0
        self._amount = value

    @property
    def empty(self) -> bool:
        return self._amount == 0.0

    @property
    def over(self) -> bool:
        return self._over

    def pour(self, additional : float) -> None:
        self.amount = self.amount + additional