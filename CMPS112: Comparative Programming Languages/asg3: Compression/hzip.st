#!/afs/cats.ucsc.edu/courses/cmps112-wm/usr/smalltalk/bin/gst -f

Object subclass: BitStream [
   |stringIndex bitIndex byte myStream writeIndex writeByte|
   BitStream class >> new: fileStream [
      |result|
      result := super new.
      result init: fileStream.
      ^result
   ]
   init: fileStream [
      myStream := fileStream.
      bitIndex := 1.
      writeIndex := 9.
      writeByte := 0.
   ]
   nextBit [
      bitIndex = 1 ifTrue: [
         byte := myStream next.
         bitIndex := 9.
      ].
      bitIndex := bitIndex - 1.
      ^byte value bitAt: bitIndex
   ]
   putBit: theBit [
      writeIndex := writeIndex - 1.
      writeByte := writeByte bitAt: writeIndex put: theBit.
      writeIndex = 1 ifTrue: [
         myStream nextPutByte: writeByte.
         writeByte := 0.
         writeIndex := 9.
      ].
   ]

   putString: theString [
      theString do: [:index|
         (index asString = '0')
            ifTrue: [self putBit: 0]
            ifFalse: [self putBit: 1].
      ].
   ]
   padOut [
      [writeIndex > 1 & writeIndex < 9] whileFalse: [
         self putBit: 0.
         writeIndex := writeIndex - 1.].
   ]
   atEnd [
      ^bitIndex = 1 and: [myStream atEnd]
   ]
]

Object subclass: ZeroArray [
    |theArray|

    ZeroArray class >> new [
        self shouldNotImplement.
    ]

    ZeroArray class >> new: size [
        |result|
        result := super new.
        result init: size.
        ^ result
    ]

    init: size [
        theArray := Array new: size.
    ]

    size [
        ^ theArray size.
    ]

    at: index [
        ^ theArray at: index + 1.
    ]

    at: index put: value [
        ^ theArray at: index + 1 put: value.
    ]

    incr: index [
        (self at: index) isNil
            ifTrue: [ self at: index put: 0].
        self at: index put: (self at: index) + 1.
    ]

    keysAndValuesDo: aBlock [
        (0 to: (self size) - 1) do: [:index |
            aBlock value: index value: (self at: index).
        ]
    ]
]

FileStream extend [
    nl := Character nl.
    catFile [
        |count|
        count := 0.
        [self atEnd not] whileTrue: [
            count := count +1.
            count asString size to: 5 do: [:skip| stdout << ' '].
            stdout << count << ': ' << self nextLine << nl.
        ]
    ]
    fParse [
      |freqtable|
      freqtable := ZeroArray new: 257.
      [self atEnd not] whileTrue: [
         |ordChar|
         ordChar := self next asInteger.
         freqtable incr: ordChar.
      ].
      freqtable incr: 256.
      ^ freqtable
    ]
]

Object subclass: Leaf [
    |char count|
    char [ ^ char ]
    count [ ^ count ]
    isLeaf [ ^ true ]
    Leaf class >> new [
        self shouldNotImplement
    ]

    Leaf class >> new: aChar count: aCount [
        |result|
        result := super new.
        result setChar: aChar andCount: aCount.
        ^result
    ]

    setChar: aChar andCount: aCount [
        char := aChar.
        count := aCount.
    ]

    <= other [
        ^ (count < other count)
        | ((count = other count) & (char <= other char))
    ]

    printBase: aStream [
    |fixhl| "Fix highlighting in vim - variable never used."
        ^ aStream << self class << '(' << char << ',' << count
    ]
    printOn: aStream [
        (self printBase: aStream) << ')'.
    ]

    inorder: visitor prefix: string [
        visitor value: char value: string.
    ]

    binTreeDump: aBitstream [
      aBitstream putBit: 0.
      (1 to: 8) do: [:index |
          aBitstream putBit: ( (self char asInteger) bitAt: index) ].
      char asInteger = 0 ifTrue: [
         aBitstream putBit: 0.
      ].
      char asInteger = 256 ifTrue: [
         aBitstream putBit: 1.
      ]

    ]

]

Leaf subclass: Tree [
   |left right|

   Tree class >> new: aChar count: aCount left: aLeft right: aRight [
       |result|
       result := super new: aChar count: aCount.
       result setLeft: aLeft andRight: aRight.
       ^ result
   ]

   isLeaf [ ^ false ]

   setLeft: aLeft andRight: aRight [
       left := aLeft.
       right := aRight.
   ]
   right [ ^ right ]
   left [ ^ left ]

   printOn: aStream [
       (self printBase: aStream) << ',' << left << ',' << right << ')'.
   ]

   inorder: visitor prefix: string [
       left inorder: visitor prefix: string, '0'.
       right inorder: visitor prefix: string, '1'.
   ]

   binTreeDump: aBitstream [
      "Left child, then right child, then print for current node."
      left binTreeDump: aBitstream.
      right binTreeDump: aBitstream.
      aBitstream putBit: 1.
   ]
]

nl := Character nl.
flagD := false.
flagC := false.
flagT := false.
flagU := false.
input := ''.
|output|
argSize := Smalltalk arguments size.

argSize = 3 ifTrue: [
   output := Smalltalk getArgv: 3.
   outFile := FileStream open: output mode: FileStream write. ]
ifFalse: [outFile := stdout.].


flag = '-d' ifTrue:  [flagD := true].
flag = '-t' ifTrue:  [flagT := true].
flag = '-c' ifTrue:  [flagC := true].
flag = '-u' ifTrue:  [flagU := true].

argSize > 3 ifTrue: [
       status := 1.
       stderr << 'Usage: ' << 'Too many arguments ' << status << nl.
       ObjectMemory quit: status.
   ].
argSize < 2 ifTrue: [
       status := 1.
       stderr << 'Usage: ' << 'Too few arguments ' << status << nl.
       ObjectMemory quit: status.
   ].

"************************************ Debug**************************"
flagD ifTrue: [
    stdout << 'Debug is on' <<  nl.
].

|inFile outFile fTable priorityQ theTree encodeTable|
inFile := FileStream open: input mode: FileStream read.
outFile := FileStream open: output mode: FileStream write.
priorityQ := SortedCollection new.

flagU ifFalse: [fTable := inFile fParse.
   (0 to: fTable size - 1)
   do: [ :index |
      |aLeaf aCount aChar|
      aCount := fTable at: index.
      aCount isInteger ifTrue: [
          aChar := index asCharacter.
          aLeaf := Leaf new: aChar  count: aCount.
          priorityQ add: aLeaf.
      ].
   ].

   [priorityQ size > 1] whileTrue: [
       |last seclast aTree treeChar treeCount|
       last := priorityQ removeFirst.
       seclast := priorityQ removeFirst.
       treeChar := last char.
       treeCount := last count + seclast count.
       aTree := Tree new: treeChar count: treeCount left: last
                                                    right: seclast.
       priorityQ add: aTree.
   ].

theTree := priorityQ removeLast.
encodeTable := ZeroArray new: 257.
theTree inorder: [:char :string |
       |index count|
       index := char asInteger.
       encodeTable at: index put: string.
   ] prefix: ''.
].

"************************************Frequency Table**************************"
flagT ifTrue: [
(0 to: encodeTable size - 1)
do: [:index |
   |char count string|
   count := fTable at: index.
   string := encodeTable at: index.
   count isInteger ifTrue: [
      (index > 32) & (index < 127) ifTrue: [
         char := index asCharacter.
         1 to: (1 - (char size)) do: [:x | stdout << ' '. ].
         stdout << char << '    ' << count+1 << '  ' << string << nl.

      ] ifFalse: [
         (index > 32) ifFalse: [ stdout << ' '. ].
         stdout << index << ' '.
         1 to: (2 - (count size)) do: [:x | stdout << ' '. ].
         (99 < count | 9 < count )ifFalse: [ stdout << ' '. ].
         stdout << count << '  ' << string << nl.
      ].
   ].
].
].

"************************************Compression**************************"
flagC ifTrue: [
   |encString|
   aBitstream := BitStream new: outFile.
   inFile reset.
   theTree binTreeDump: aBitstream.
   aBitstream putBit:
   [inFile atEnd not] whileTrue: [
      |index|
      index := inFile next asInteger.
      encString := (encodeTable at: index).
      aBitstream putString: encString.
   ].
   encString := encodeTable at: 256.
   aBitstream putString: encString.
   aBitstream padOut.
   inFile close.
   outFile close.
].
"************************************Uncompression**************************"
flagU ifTrue: [
 stdout << 'Not implemented' << nl.
   ].

   inFile close.
   outFile close.
