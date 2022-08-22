import abc  # Python's built-in abstract class library

#Sound Strategy
class SoundStrategyAbstract(object):
    """Metaclasses"""
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def sound(self):
        print("")
#Algorithm 1
class LoudSoundStrategy(SoundStrategyAbstract): 
    def sound(self):
        print ("AHHH!")
#Algorithm 2
class QuietSoundStrategy(SoundStrategyAbstract): 
    def sound(self):
        print ("Hya!")

#Move Strategy
class MoveStrategyAbstract(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def move(self):
        print("")
#Algorithm 1
class PunchStrategy(MoveStrategyAbstract):
    def move(self):
        print ("PUNCH")
#Algorithm 2
class KickStrategy(MoveStrategyAbstract):
    def move(self):
        print ("KICK")

loud = LoudSoundStrategy()
quiet = QuietSoundStrategy()
punch = PunchStrategy()
kick = KickStrategy()

#Context
class Fighter(object):
    def __init__(self, sound_strategy, move_strategy):
        self._sound_strategy = sound_strategy
        self._move_strategy = move_strategy

    def sound(self):
        self._sound_strategy.sound()

    def move(self):
        self._move_strategy.move()


class NinjaFighter(Fighter):
    def __init__(self):
        super(NinjaFighter, self).__init__(quiet, kick)

class SumoFighter(Fighter):
    def __init__(self):
        super(SumoFighter, self).__init__(loud, punch)

class BoxFighter(Fighter):
    def __init__(self):
        super(BoxFighter, self).__init__(None, punch)

#Makes it easy to add a fighter and establish their sound and move
class KungFuFighter(Fighter):
    def __init__(self):
        super(KungFuFighter, self).__init__(quiet, None)

#prints NinjaFighter sound and move
nin = NinjaFighter()
nin.sound()
nin.move()
