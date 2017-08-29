# valueIterationAgents.py
# -----------------------
# Licensing Information: Please do not distribute or publish solutions to this
# project. You are free to use and extend these projects for educational
# purposes. The Pacman AI projects were developed at UC Berkeley, primarily by
# John DeNero (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# For more info, see http://inst.eecs.berkeley.edu/~cs188/sp09/pacman.html

import mdp, util

from learningAgents import ValueEstimationAgent

class ValueIterationAgent(ValueEstimationAgent):
  """
      * Please read learningAgents.py before reading this.*

      A ValueIterationAgent takes a Markov decision process
      (see mdp.py) on initialization and runs value iteration
      for a given number of iterations using the supplied
      discount factor.
  """
  def __init__(self, mdp, discountRate = 0.9, iters = 100):
    """
      Your value iteration agent should take an mdp on
      construction, run the indicated number of iterations
      and then act according to the resulting policy.

      Some useful mdp methods you will use:
          mdp.getStates()
          mdp.getPossibleActions(state)
          mdp.getTransitionStatesAndProbs(state, action)
          mdp.getReward(state, action, nextState)
    """
    self.mdp = mdp
    self.discountRate = discountRate
    self.iters = iters
    self.values = util.Counter() # A Counter is a dict with default 0

    """Description:
    [This will get the values of the state of the mdp after a certain number
    of iterations. Everytime it goes through an iteration it creates a new Counter
    the for each state it gets the bestaction. After getting the best action by
    using the getAction(). If we are at the terminal state then it will return None
    in which case we return the current value of the state. Otherwise we update the
    currentValue counter. After we are done we update the values for the run with new values.
    We do this over and over until all iterations are done.]
    """
    """ YOUR CODE HERE """

    """Loop through all iterations"""
    for iter in range(self.iters):
        """New counter for each iteration"""
        currentValues = util.Counter()
        """check the best action and value for each state"""
        for state in self.mdp.getStates():
            action = self.getAction(state)
            """update the values of the current state"""
            if action != None:
                currentValues[state] = self.getQValue(state, action)
            else:
                currentValues[state] = self.getValue(state)
        """Update the values from previous iterations"""
        self.values = currentValues


    """ END CODE """

  def getValue(self, state):
    """
      Return the value of the state (computed in __init__).
    """
    return self.values[state]

    """Description:
    [It returns the values from the iteration. It will be zero to begin with]
    """
    """ YOUR CODE HERE """
    util.raiseNotDefined()
    """ END CODE """

  def getQValue(self, state, action):
    """
      The q-value of the state action pair
      (after the indicated number of value iteration
      passes).  Note that value iteration does not
      necessarily create this quantity and you may have
      to derive it on the fly.
    """
    """Description:
    [It obtains the q value for a certain state and action. It first gets all
    values necessary for the calculation of the values such as the nextState,
    the probability, the realvalue of the nextState since there is a change that
    there is no movemennt. We then add the next StateRealValue and the reward
    and multiply by the probability. We then add all the values since we want to
    get a sense of how good all the nextstates are for this state.]
    """
    """ YOUR CODE HERE """
    value = 0
    for trans in self.mdp.getTransitionStatesAndProbs(state, action):
      """Values used in the calculation of the value"""
      nextState = trans[0]
      probability = trans[1]
      nextStateRealValue = self.getValue(nextState)* self.discountRate
      reward = self.mdp.getReward(state, action, nextState)

      """Sum the value after all the iterations for this state"""
      value += ((nextStateRealValue + reward)* probability)
    return value
    """ END CODE """

  def getPolicy(self, state):
    """
      The policy is the best action in the given state
      according to the values computed by value iteration.
      You may break ties any way you see fit.  Note that if
      there are no legal actions, which is the case at the
      terminal state, you should return None.
    """

    """Description:
    [We make the bestAction be None to begin with. if there are action that can
    be taken then its not the terminal state thus bestaction cannot be none.
    Thus we make the best action the current action. We iterate through all the
    possible action for this state and compare which one has a higher value. If
    the current action is better then we make that the bestaction. If there is a
    tie then we make the new action the best action.]
    """
    """ YOUR CODE HERE """
    bestAction = None
    for action in self.mdp.getPossibleActions(state):
      """ If there is a possible action and not terminal then make it best action"""
      if (bestAction == None):
        bestAction = action  
      else:
        """Else we check if the current action is the best."""
        currentActionValue = self.getQValue(state, action)
        bestActionValue = self.getQValue(state, bestAction)
        if(currentActionValue > bestActionValue):
            bestAction = action
    return bestAction
    """ END CODE """

  def getAction(self, state):
    "Returns the policy at the state (no exploration)."
    return self.getPolicy(state)
