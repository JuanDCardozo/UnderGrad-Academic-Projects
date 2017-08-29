# analysis.py
# -----------
# Licensing Information: Please do not distribute or publish solutions to this
# project. You are free to use and extend these projects for educational
# purposes. The Pacman AI projects were developed at UC Berkeley, primarily by
# John DeNero (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# For more info, see http://inst.eecs.berkeley.edu/~cs188/sp09/pacman.html

######################
# ANALYSIS QUESTIONS #
######################

# Change these default values to obtain the specified policies through
# value iteration.

def question2():
  answerDiscount = 0.9
  answerNoise = 0.2
  """Description:
  [The number 0.01519 is the limit for noise when creating positive numbers
  the bridge so that the agent will take the bridge. If noise is greater than
  that it will give negative numbers, but it will still take the bridge if
  its smaller than 0.169 since the next states have a higher reward. The reason
  the noise is the deciding factor, is because the terminal states surrounding
  the bridge are too high, so the risk of taking the state needs to be
  extremely small for the bridge to be a good option]
  """
  """ YOUR CODE HERE """
  answerNoise = 0.01519
  """ END CODE """
  return answerDiscount, answerNoise

def question3a():
  answerDiscount = 0.9
  answerNoise = 0.2
  answerLivingReward = 0.0
  """Description:
  [To make the agent take the first terminal with +1 risking getting the -10.
  We need to punish the agent for staying alive on the board too long. However,
  if this number is not big enough then it might go to the terminal with +10
  since the reward is biggger than the punishment for staying allive. So -2.5
  seems to be the sweet spot for not going over to the +10 terminal.]
  """
  """ YOUR CODE HERE """
    answerLivingReward = -2.5
  """ END CODE """
  return answerDiscount, answerNoise, answerLivingReward
  # If not possible, return 'NOT POSSIBLE'

def question3b():
  answerDiscount = 0.9
  answerNoise = 0.2
  answerLivingReward = 0.0
  """Description:
  [If we want to go along the cliff and get to the terminal with +1 we have to
  punish the agent for living and the noise has to be very small or null.
  However, if living is costs more than the cliff then the agent will go
  over the cliff, therefore the punishment has to be greater than -10. ]
  """
  """ YOUR CODE HERE """
  answerLivingReward = -5.0
  answerNoise = 0.01
  """ END CODE """
  return answerDiscount, answerNoise, answerLivingReward
  # If not possible, return 'NOT POSSIBLE'

def question3c():
  answerDiscount = 0.9
  answerNoise = 0.2
  answerLivingReward = 0.0
  """Description:
  [If we want to go along the cliff and get to the terminal with +10 we have to
  punish the agent for living and the noise has to be very small or null.
  In addition, the punishment for living has to be small enough so that the +10
  is more adventageous than the +1. Since living is more expensive than the +1,
  the agent will go to the +10]
  """
  """ YOUR CODE HERE """
  answerNoise = 0.01
  answerLivingReward = -1.0
  """ END CODE """
  return answerDiscount, answerNoise, answerLivingReward
  # If not possible, return 'NOT POSSIBLE'

def question3d():
  answerDiscount = 0.9
  answerNoise = 0.2
  answerLivingReward = 0.0
  """Description:
  [If we want to completely avoid the cliff then we have to increase the noise,
  as to make it risky to be on the edge as it is more likely to miss the Rights
  states. However, the noise cannot be too high (0.4 or greater) since this
  could accidentaly lead to falling over the cliff. Also there cannot be a
  punishment for living, since then the agent will prefer to go to the higher
  terminal point.]
  """
  """ YOUR CODE HERE """
  answerNoise = 0.3

  """ END CODE """
  return answerDiscount, answerNoise, answerLivingReward
  # If not possible, return 'NOT POSSIBLE'

def question3e():
  answerDiscount = 0.9
  answerNoise = 0.2
  answerLivingReward = 0.0
  """Description:
  [If we have a huge reward for living, then the other values will not matter
  that much since the agent will prefer to stay alive than to get to the
  terminal state and/or fall of the cliff.]
  """
  """ YOUR CODE HERE """
  answerLivingReward = 100.0
  """ END CODE """
  return answerDiscount, answerNoise, answerLivingReward
  # If not possible, return 'NOT POSSIBLE'

def question6():
  answerEpsilon = None
  answerLearningRate = None
  """Description:
  [Enter a description of what you did here.]
  """
  """ YOUR CODE HERE """

  """ END CODE """
  return answerEpsilon, answerLearningRate
  # If not possible, return 'NOT POSSIBLE'

if __name__ == '__main__':
  print 'Answers to analysis questions:'
  import analysis
  for q in [q for q in dir(analysis) if q.startswith('question')]:
    response = getattr(analysis, q)()
    print '  Question %s:\t%s' % (q, str(response))
