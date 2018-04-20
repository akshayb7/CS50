import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        self.positive=[]
        pos = open(positives,"r")
        for line in pos:
            if not line.startswith(";"):
                self.positive.append(line.rstrip("\n"))
        pos.close()

        self.negative=[]
        neg = open(negatives,"r")
        for line in neg:
            if not line.startswith(";"):
                self.negative.append(line.rstrip("\n"))
        neg.close()


    def analyze(self, text):
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        sum = 0
        for word in tokens:
            if word.lower() in self.positive:
                sum+=1
            elif word.lower() in self.negative:
                sum-=1
            else:
                continue
        return sum