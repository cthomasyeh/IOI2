Imports System.IO
Imports System.Resources
Imports System.Reflection

Public Class FishForm

    ' All variables, constants, and structures are provided complete in the Activity Starter
    Dim centerHeight, centerWidth As Integer    'These variables will hold the center point for the screen

    Dim myGameState As GameState    'This variable will hold the current game state

    Dim myRandomGenerator As New System.Random   'This is a random number generator that we will use in the game

    'These variables will hold the card images for the game
    Dim deckImage As Image
    Dim faceDownCard As Image

    'Following are constant values that will be used in the game
    Const NO_CARD_SELECTED = -1

    Const CARD_WIDTH = 71       'The width of the card, in pixels
    Const CARD_HEIGHT = 96      'The height of the card, in pixels
    Const CARD_OVERLAP = 30     'The amount that the cards will overlap on the screen, in pixels
    Const CARD_SELECTION_OFFSET = 10    'The amount that a card will be offset vertically when it is selected by the user

    'This enumeration will give meaningful names to the players in the game
    Private Enum PlayerType
        NONE = 0
        COMPUTER = 1
        HUMAN = 2
    End Enum

    'This enumeration will give meaningful names to the card suits
    Private Enum CardSuit
        Clubs = 0
        Hearts = 1
        Spades = 2
        Diamonds = 3
    End Enum

    'A Card is a data structure that holds a Sprite and several other important pieces of data
    Private Structure Card
        Dim mySprite As Sprite      'The Sprite for the card
        Dim suit As CardSuit        'The suit for the card
        Dim isInBook As Boolean     'Whether or not the card is already in a book
        Dim currentPlayer As PlayerType 'Who currently has the card in their hand or book
        Dim cardName As String      'The name of the card, not including suit ("1", "Ace", etc).
    End Structure


    'The GameState is a data structure that holds all of the important game information
    Private Structure GameState
        Dim deckOfCards() As Card               'This is the deck of 52 cards for the game

        Dim iCurrentPlayer As Integer           'The current player in the game
        Dim iCurrentCardSelected As Integer     'The current card selected (an index into the deckOfCards array)
        Dim iNumComputerBooks As Integer        'The number of complete books the computer has
        Dim iNumHumanBooks As Integer           'The number of complete books the human player has
        Dim gameOver As Boolean                 'Whether or not the game is over
        Dim iCardsInDeck As Integer             'The number of cards that are left in the deck (not in anyone's hand)

        ' DoBetterAI uses the following game state notes
        Dim humansCards() As String             'The cards that the human player has already asked for
    End Structure

    ' This method provided complete in the Activity Starter
    ' This function will initialize the game
    Private Sub FishForm_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load

        'Here we will set all of the initial information in our game state
        myGameState.iCurrentPlayer = PlayerType.HUMAN           'The human player gets to go first
        myGameState.iCurrentCardSelected = NO_CARD_SELECTED     'When the game starts, no card is selected
        myGameState.iNumComputerBooks = 0                       'There are no books for the computer
        myGameState.iNumHumanBooks = 0                          'There are no books for the human
        myGameState.gameOver = False                            'The game is not over
        myGameState.iCardsInDeck = 52                            'Since no cards have been dealt yet, the deck still has 52 cards in it
        ReDim myGameState.deckOfCards(51)                       'Here we ReDim the deckOfCards array to account for 52 cards in a normal deck

        'This array will be used for the DoBetterAI() function
        ReDim myGameState.humansCards(0)                        'Here we ReDim the humanCards array to hold 1 string

        ' calculate the center width and height for future use
        centerWidth = Me.ClientRectangle.Width / 2
        centerHeight = Me.ClientRectangle.Height / 2

        'Call the InitializeCards function to set the card information for the deck of cards
        InitializeCards()

        'Deal each player 7 cards using the DealCard function
        For i = 1 To 7
            DealCard(PlayerType.COMPUTER, False)
            DealCard(PlayerType.HUMAN, False)
        Next

        'Set the deck of cards image
        deckImage = My.Resources.DeckOfCards

        'Set the face down card image
        faceDownCard = My.Resources.FaceDownCard

    End Sub

    ' This method provided complete in the Activity Starter
    ' This function will initialize all of the cards in the deck
    Private Sub InitializeCards()
        Dim iCardNumber As Integer = 0

        'The value of any card is a number between 1 and 13
        For iCardValue = 1 To 13
            For iSuit = 0 To 3  'There are 4 suits in a deck of cards

                iCardNumber = (iCardValue - 1) * 4 + iSuit  'We create a unique index for our card

                myGameState.deckOfCards(iCardNumber).suit = iSuit
                myGameState.deckOfCards(iCardNumber).isInBook = False
                myGameState.deckOfCards(iCardNumber).currentPlayer = PlayerType.NONE
                myGameState.deckOfCards(iCardNumber).cardName = GetCardName(iCardValue)

                myGameState.deckOfCards(iCardNumber).mySprite = New Sprite()
                myGameState.deckOfCards(iCardNumber).mySprite.Size = New Point(CARD_WIDTH, CARD_HEIGHT)
                myGameState.deckOfCards(iCardNumber).mySprite.IsAlive = False ' all cards are initially invisible
                myGameState.deckOfCards(iCardNumber).mySprite.SetImageResource(GetCardResourceName(iSuit, iCardValue))
            Next
        Next

    End Sub

    ' This method provided complete in the Activity Starter
    ' This function will take the numeric value of a card (1-13) and return the card's true name 
    Private Function GetCardName(ByVal iCardValue As Integer) As String

        Dim cardName As String = ""

        If (iCardValue = 1) Then
            cardName = "Ace"
        ElseIf (iCardValue <= 10) Then
            cardName = Format(iCardValue, "D") ' use Format instead of Str to avoid leading space in output
        ElseIf (iCardValue = 11) Then
            cardName = "Jack"
        ElseIf (iCardValue = 12) Then
            cardName = "Queen"
        ElseIf (iCardValue = 13) Then
            cardName = "King"
        End If

        Return cardName
    End Function

    ' This method provided complete in the Activity Starter
    ' This function will deal a single card to a player
    Private Function DealCard(ByVal player As PlayerType, ByVal displayCard As Boolean) As Integer

        'Create a variable that will hold our random card number
        Dim iRandomCard As Integer

        ' what if no cards are left in the deck?
        If (myGameState.iCardsInDeck = 0) Then
            Return NO_CARD_SELECTED
        End If

        'This loop will pull a random card from the deck. If the card does not already belong to a player 
        'The card will be dealt to the player that has requested the new card
        Do
            iRandomCard = myRandomGenerator.Next(0, 52)  ' >=0 and < 52
            ' if nobody yet owns this card
            If (myGameState.deckOfCards(iRandomCard).currentPlayer = PlayerType.NONE) Then
                myGameState.deckOfCards(iRandomCard).currentPlayer = player ' target player now owns this card
                myGameState.deckOfCards(iRandomCard).mySprite.IsAlive = True ' card is now visible
                myGameState.iCardsInDeck -= 1   ' there is now one less card in the deck

                ' if calling function wants us to display which card is dealt to human in a pop-up MsgBox
                If (displayCard = True) Then
                    If (player = PlayerType.COMPUTER) Then
                        'This would be cheating :)
                        'MsgBox("Computer is dealt a " & myGameState.deckOfCards(iRandomCard).cardName)
                    Else
                        ' display the name ofthe card that the human player was dealt
                        MsgBox("You are dealt a " & myGameState.deckOfCards(iRandomCard).cardName)
                    End If
                End If
                Exit Do
            End If
        Loop

        ' each time a new card is added to a player's hand we need to check and see
        ' if that card completes a book for the player
        CheckForBooks(player, iRandomCard)

        ' we also want to re-display the player's hand to show the new card
        DisplayHand(player)

        ' return the card index that was dealt in case the calling function wants to use the information
        Return iRandomCard
    End Function

    ' This method provided complete in the Activity Starter
    ' This function will check the specified player's hand for a complete book of the specified card index
    Private Function CheckForBooks(ByVal player As PlayerType, ByVal cardNumber As Integer) As Boolean

        Dim isBookMade As Boolean = False   ' assume no book is made
        Dim iCardInBookCount As Integer = 0 ' count of how many of the target cards are in player's hand
        Dim cardsInBook(3) As Integer       ' array containing the index value of the target cards found

        ' for each card in the deck
        For i = 0 To 51

            ' if the card belongs to the target player
            If (myGameState.deckOfCards(i).currentPlayer = player) Then
                ' if the name of this card matches the name of the target card
                If (myGameState.deckOfCards(i).cardName = myGameState.deckOfCards(cardNumber).cardName) Then

                    ' count this card as being in the book and save the card's index for future reference
                    cardsInBook(iCardInBookCount) = i
                    iCardInBookCount += 1
                End If
            End If

            ' if we have matched a set of 4 of the target card, then we've made a book!
            If (iCardInBookCount = 4) Then

                ' for the computer player
                If (player = PlayerType.COMPUTER) Then

                    ' let the human player know what happened and add to the computer's score
                    MsgBox("Computer makes a book of " & myGameState.deckOfCards(cardsInBook(0)).cardName & "s!")
                    myGameState.iNumComputerBooks += 1

                Else    ' for the human player
                    ' let the human player know what happened and add to the human's score
                    MsgBox("You make a book of " & myGameState.deckOfCards(cardsInBook(0)).cardName & "s!")
                    myGameState.iNumHumanBooks += 1
                End If

                ' we now need to move each of the cards in the book out of the hand into a book
                For j = 0 To 3

                    ' mark the card as being in a book
                    myGameState.deckOfCards(cardsInBook(j)).isInBook = True
                    myGameState.deckOfCards(cardsInBook(j)).mySprite.IsAlive = False ' card is now invisible

                Next

                ' set flag to true indicating a book was made
                isBookMade = True

                ' re-display the player's hand as some cards are now gone
                DisplayHand(player)

                Invalidate()    ' make sure whole screen is repainted so book count will increment

                ' break out of the For loop immediately; we don't need to look any further!
                Exit For

            End If
        Next

        ' return the flag showing if a book was made, in case the calling function needs to use that information
        Return isBookMade
    End Function

    ' This method provided complete in the Activity Starter
    ' This function will display the target player's current hand.
    Private Sub DisplayHand(ByVal player As PlayerType)

        ' figure out how many cards the player has in their hand
        Dim numPlayerCards = GetNumberOfCardsInHand(player)

        ' define a count of the displayed cards, to be used to obtain the card location
        Dim displayCardNumber As Integer = 0

        Dim i As Integer    ' loop index variable

        ' for each card in the deck
        For i = 0 To 51
            ' if this card is owned by the target player and is not in a book
            If ((myGameState.deckOfCards(i).currentPlayer = player) And (myGameState.deckOfCards(i).isInBook = False)) Then

                ' calculate the new "unselected" card location for this card
                Dim cardLocation As Point = GetCardLocation(player, numPlayerCards, displayCardNumber)

                ' set the card sprite's upper left position on the screen
                myGameState.deckOfCards(i).mySprite.UpperLeft = cardLocation

                ' increment the displayCardNumber to space the next card out in the next slot
                displayCardNumber += 1

            End If
        Next
        Invalidate()
    End Sub

    ' This method provided complete in the Activity Starter
    ' This function will count the number of cards currently in the specified player's hand
    Private Function GetNumberOfCardsInHand(ByVal player As PlayerType) As Integer

        Dim iNumOfCards As Integer = 0  ' assume no cards in the hand to start

        ' for each of the 52 cards in the deck
        For i = 0 To 51

            ' if this card belongs to the target player and is not in a book
            If (myGameState.deckOfCards(i).currentPlayer = player) And (myGameState.deckOfCards(i).isInBook = False) Then
                ' count the card
                iNumOfCards += 1
            End If
        Next

        ' return the card count to the calling function
        Return iNumOfCards
    End Function

    ' This method provided complete in the Activity Starter
    ' Given a Suit and card name, calculate the complete filename of the card image.
    Private Function GetCardResourceName(ByVal iFace As Integer, ByVal cardName As String) As Image
        Dim cardImage As Image

        ' start with the base image directory
        Dim strFileName As String = ""

        ' determine which suit is requested
        Select iFace
            Case CardSuit.Clubs
                strFileName = "Club"       ' first part of Clubs filenames is "Club"
            Case CardSuit.Diamonds
                strFileName = "Diamond"    ' first part of Diamonds filenames is "Diamond"
            Case CardSuit.Hearts
                strFileName = "Heart"      ' first part of Hearts filenames is "Heart"
            Case CardSuit.Spades
                strFileName = "Spade"      ' first part of Spades filenames is "Spade"
        End Select

        ' now add on the card name ("Ace", "1", etc) 
        strFileName &= cardName

        cardImage = My.Resources.ResourceManager.GetObject(strFileName)

        Return cardImage  ' return the completed filename to the calling function
    End Function


    ' This method provided complete in the Activity Starter
    ' This function will handle the mouse click, which may select a card
    Private Sub FishForm_MouseClick(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles Me.MouseClick

        ' assume that no card was selected by the mouse click
        Dim iCardSelected As Integer = NO_CARD_SELECTED

        ' check each of the 52 cards in the deck
        For i = 0 To 51
            ' if the card's sprite returns true for IsClicked
            If (myGameState.deckOfCards(i).mySprite.IsClicked(e.Location)) Then
                ' save the selected card index
                iCardSelected = i
            End If
        Next

        ' if any card was selected
        If (iCardSelected <> NO_CARD_SELECTED) Then

            ' if the card belongs to the currnet player
            If (myGameState.deckOfCards(iCardSelected).currentPlayer = myGameState.iCurrentPlayer) Then

                ' if the card is not already selected
                If (iCardSelected <> myGameState.iCurrentCardSelected) Then

                    ' select the card
                    SelectCard(iCardSelected)
                End If
            End If
        End If
    End Sub

    ' This method provided complete in the Activity Starter
    ' This function will paint the entire game screen
    Private Sub FishForm_Paint(ByVal sender As Object, ByVal e As System.Windows.Forms.PaintEventArgs) Handles Me.Paint
        Dim myGraphics As Graphics = e.Graphics

        Dim myDeckLocation As Point ' the upper left coordinate of the draw deck image

        ' if there are any cards left in the deck
        If (myGameState.iCardsInDeck > 0) Then

            ' calculate the upper-left position of the draw deck image
            myDeckLocation.X = centerWidth - deckImage.Width / 2
            myDeckLocation.Y = centerHeight - deckImage.Height / 2

            ' show the draw deck image on the screen
            myGraphics.DrawImage(deckImage, myDeckLocation)
        End If

        'Go thru Card Deck and display Computer's cards and Player's cards
        For i = 0 To 51

            ' if this card is owned by some player and is not already in a book, then it must be in a hand
            If ((myGameState.deckOfCards(i).currentPlayer <> PlayerType.NONE) And (myGameState.deckOfCards(i).isInBook <> True)) Then

                ' during development you may wish to see the computer player's hand so you can tell if the 
                ' AI algorithms are wokring correctly.  
                Dim hideComputerHand As Boolean = True ' change this to False if you want to peek at the computer hand!

                ' if this card's owner is the computer and we want to hide the computer's hand
                If ((myGameState.deckOfCards(i).currentPlayer = PlayerType.COMPUTER) And hideComputerHand) Then
                    ' draw the image of a face down card within the sprite's bounding rectangle
                    myGraphics.DrawImage(faceDownCard, myGameState.deckOfCards(i).mySprite.GetBoundingRectangle())
                Else
                    ' draw the image of the face-up card within the sprite's bounding rectangle
                    myGameState.deckOfCards(i).mySprite.PaintImage(myGraphics, False)
                End If
            End If
        Next

        ' Now we need to display the number of books each player has scored

        ' create new FontFamily, Font, and Brush.
        Dim fontFamily As New FontFamily("Arial")
        Dim font As New Font(fontFamily, 16, FontStyle.Regular, GraphicsUnit.Pixel)
        Dim brush As System.Drawing.SolidBrush = New System.Drawing.SolidBrush(Color.Red)

        ' calculate an X position in the middle of the screen
        Dim xPosition = centerWidth

        ' calculate a Y position for the computer 10 pixels below the bottom of an unselected card
        Dim yComputerText = GetUnselectedCardY(PlayerType.COMPUTER) + CARD_HEIGHT + 10

        ' calculate the Y position for the human 20 pixels above the top of an unselected card
        Dim yHumanText = GetUnselectedCardY(PlayerType.HUMAN) - CARD_SELECTION_OFFSET - 20

        ' draw both scores using the DrawString method.
        myGraphics.DrawString(Str(myGameState.iNumComputerBooks) & " Book(s)", font, brush, xPosition, yComputerText)
        myGraphics.DrawString(Str(myGameState.iNumHumanBooks) & " Book(s)", font, brush, xPosition, yHumanText)

    End Sub


    ' This method provided complete in the Activity Starter
    ' This function will calculate the Y coordinate of an unselected card for the target player
    Private Function GetUnselectedCardY(ByVal player As PlayerType)

        Dim Y As Integer    ' this is the return variable

        ' if target player is the computer
        If player = PlayerType.COMPUTER Then
            ' this is our unselected card offset for the computer
            Y = 15
        ElseIf player = PlayerType.HUMAN Then
            ' this is our unselected card offset for the human (based on window size)
            Y = Me.ClientSize.Height - CARD_HEIGHT - 5
        End If

        Return Y
    End Function

    ' This method provided complete in the Activity Starter
    ' This function will return a Point containing the upper-left coordinate of a card to be drawn on the screen
    Private Function GetCardLocation(ByVal player As PlayerType, ByVal numPlayerCards As Integer, ByVal displayCardIndex As Integer) As Point
        Dim startingPoint As Point

        ' The Y coordinate is easy...one of two values as determined by the player
        startingPoint.Y = GetUnselectedCardY(player)

        ' The X coordinate is trickier.  We need to know how many cards are in the player's hand, which card
        ' we are trying to draw, what the width of a card is, and where the center of the screen is.
        startingPoint.X = (centerWidth - CARD_WIDTH) - ((numPlayerCards \ 2) * CARD_OVERLAP) + CARD_OVERLAP * displayCardIndex

        ' return the completed point to the calling function
        Return startingPoint

    End Function

    ' This method provided complete in the Activity Starter
    ' This function implements all of the logic involved with asking a player for a card
    Private Sub AskForCard(ByVal player As PlayerType, ByVal cardNumber As Integer)

        Dim isCardFound As Boolean = False  ' assume no card found
        Dim cardReceived = cardNumber       ' declare variable for the card index we received

        ' if a specific card was requested
        If (cardNumber <> NO_CARD_SELECTED) Then
            ' attempt to take those cards from the opponent's hand
            isCardFound = TakeCards(player, cardNumber)
        End If

        ' Did we get a card from the opponent?
        If (isCardFound = True) Then
            ' see if we formed abook
            CheckForBooks(player, cardNumber)
        Else
            'Go Fish
            If (player = PlayerType.HUMAN) Then
                MsgBox("Sorry! Go Fish!", MsgBoxStyle.OkOnly, "Go Fish")
            Else
                MsgBox("Computer must Go Fish!", MsgBoxStyle.OkOnly, "Go Fish")
            End If

            ' deal a new card to the player that has to Go Fish
            cardReceived = DealCard(player, True)
        End If

        ' game is over if there are no cards left in the deck or if any player has no cards in hand!
        If (myGameState.iCardsInDeck = 0) Then
            myGameState.gameOver = True
        ElseIf (GetNumberOfCardsInHand(PlayerType.HUMAN) = 0) Then
            myGameState.gameOver = True
        ElseIf (GetNumberOfCardsInHand(PlayerType.COMPUTER) = 0) Then
            myGameState.gameOver = True
        End If

        'unselect current card, if any
        UnselectCard()

        'change player only if game is not over
        If (myGameState.gameOver = False) Then

            Dim switchPlayer As Boolean = False    ' assume we're not switching players

            ' Players get another turn if they did not have to Go Fish, or if they drew the card they were
            ' asking for from the desk.

            ' if no particular card was requested 
            If (cardNumber = NO_CARD_SELECTED) Then
                switchPlayer = True ' we will switch to the next player

                ' else if the card we received is not the same as the card we asked for
            ElseIf (myGameState.deckOfCards(cardReceived).cardName <> myGameState.deckOfCards(cardNumber).cardName) Then

                switchPlayer = True ' we will switch to the next player

                ' if the card we received is the same as the card we asked for but it didn't come from the opposing player
            ElseIf ((myGameState.deckOfCards(cardReceived).cardName = myGameState.deckOfCards(cardNumber).cardName) And _
                    (isCardFound = False)) Then

                ' display a message to let the human player know why somebody gets another turn
                If (player = PlayerType.HUMAN) Then
                    MsgBox("You drew the card you asked for, go again!", MsgBoxStyle.OkOnly, "Take another turn")
                Else
                    MsgBox("Computer drew the card it asked for, and will go again!", MsgBoxStyle.OkOnly, "Take another turn")
                End If

            End If

            ' if we need to switch players
            If (switchPlayer = True) Then

                ' if current player is the computer, make the current player human
                If (player = PlayerType.COMPUTER) Then
                    myGameState.iCurrentPlayer = PlayerType.HUMAN

                    ' if current player is human, make the current player the computer
                Else
                    myGameState.iCurrentPlayer = PlayerType.COMPUTER
                End If
            End If

        End If

    End Sub

    ' This method provided complete in the Activity Starter
    ' This function will track each card the human asks for in a special game state array.
    ' This game state array will only be used by the smarter artificial intelligence to make good choices.
    Private Sub TrackHumansCards(ByVal currentCard As Integer)

        ' get the name of the card human is asking for
        Dim cardName As String = myGameState.deckOfCards(currentCard).cardName

        ' define a flag that indicates if we already know about this card in our tracking array
        Dim weAlreadyKnow As Boolean = False    ' assume this is a new card

        ' see if we have this card in our tracking array
        For i = 0 To myGameState.humansCards.Length - 1

            ' if the new card name is equal to an element in our tracking array
            If (cardName = myGameState.humansCards(i)) Then
                weAlreadyKnow = True    ' flag that we already know about this card
            End If
        Next

        ' if we don't already know about this card, expand our tracking array and add it
        If (weAlreadyKnow = False) Then

            ' increase size by 1, preserving whatever was already there
            ReDim Preserve myGameState.humansCards(myGameState.humansCards.Length)

            ' add new card name to the end of the array
            myGameState.humansCards(myGameState.humansCards.Length - 1) = cardName
            'For i = 0 To myGameState.humansCards.Length - 1
            'MsgBox("card name: " & myGameState.humansCards(i))
            'Next

        End If

    End Sub

    ' This method provided complete in the Activity Starter
    ' This function handles the mouse click on the Ask button
    Private Sub AskButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AskButton.Click

        ' Don't let the human click on the ask button if it's not their turn!
        If (myGameState.iCurrentPlayer <> PlayerType.HUMAN) Then
            Return
        End If

        ' If the game is over, ignore any button clicks
        If (myGameState.gameOver = True) Then
            Return
        End If

        ' if the human player has any cards in their hand
        If (GetNumberOfCardsInHand(PlayerType.HUMAN) > 0) Then

            ' but they have not yet selected a card
            If (myGameState.iCurrentCardSelected = NO_CARD_SELECTED) Then
                ' then ignore this click
                Return  ' no card selected
            End If

        End If

        ' if we get here, then it's the human's turn, the game is not over, and the human
        ' has properly selected a card to ask for

        ' for DoBetterAI, keep track of card human is asking for
        TrackHumansCards(myGameState.iCurrentCardSelected)

        ' Ask for the selected card!
        ' myGameState.iCurrentCardSelected should be NO_CARD_SELECTED if there are no cards in player's hand
        AskForCard(myGameState.iCurrentPlayer, myGameState.iCurrentCardSelected)

        ' As a result of AskForCard, it may or may not have switched over to the computer's turn.

        ' while it's now the computer's turn and the game is not over
        ' (myGameState.gameOver will be true if there are no cards left in the deck!)
        While ((myGameState.iCurrentPlayer = PlayerType.COMPUTER) And _
               (myGameState.gameOver = False))

            ' this variable will be the card the computer wants to ask for
            Dim selectedCard As Integer = NO_CARD_SELECTED

            ' count number of cards the computer owns, and just draw if player doesn't have any!!!
            If (GetNumberOfCardsInHand(PlayerType.COMPUTER) > 0) Then

                ' call the DoBetterAI() method to select a card.
                selectedCard = DoBetterAI()

                ' if we found a card to select
                If (selectedCard <> NO_CARD_SELECTED) Then

                    ' show the card as visually selected
                    SelectCard(selectedCard)    ' visually mark the card the computer selected

                    ' let the user know what the computer is doing
                    MsgBox("Computer asks for: " & myGameState.deckOfCards(myGameState.iCurrentCardSelected).cardName, MsgBoxStyle.OkOnly, "Computer Asks for a Card")
                End If
            End If

            ' try to take the selected card (if any) from human, and Go Fish if needed
            AskForCard(PlayerType.COMPUTER, selectedCard)

        End While

        ' if the game is over 
        If (myGameState.gameOver = True) Then
            displayWinner()
        End If

    End Sub

    ' This method provided complete in the Activity Starter
    ' This function will display the winner message based on the number of books
    Private Sub displayWinner()

        ' if the computer has more books than the human
        If (myGameState.iNumComputerBooks > myGameState.iNumHumanBooks) Then
            MsgBox("The computer has won!", MsgBoxStyle.OkOnly, "Game Over")

            ' if the human has more books than the computer
        ElseIf (myGameState.iNumHumanBooks > myGameState.iNumComputerBooks) Then
            MsgBox("You have won!", MsgBoxStyle.OkOnly, "Game Over")

            ' oh no, a tie!
        Else
            MsgBox("The game is a tie!", MsgBoxStyle.OkOnly, "Game Over")
        End If

    End Sub

    ' This method will be completed by the student in a Your Turn activity 
    ' This function should return the card index into the card array of the card
    ' that the computer player should ask for
    Private Function DoAI() As Integer

        ' This method is the artificial intelligence for the computer opponent.
        ' Based on the game state, need to select and return a card number to ask for.
        Dim iRandomCard As Integer = NO_CARD_SELECTED
        Dim isCardSelected As Boolean = False

        ' Students code goes here
        Dim numCardsInHand As Integer = GetNumberOfCardsInHand(PlayerType.COMPUTER)

        If (numCardsInHand = 0) Then
            Return NO_CARD_SELECTED
        Else
            Do While (isCardSelected = False)
                iRandomCard = myRandomGenerator.Next(0, 52)
                Dim randomCard As Card = myGameState.deckOfCards(iRandomCard)
                If (randomCard.currentPlayer = PlayerType.COMPUTER) And (randomCard.isInBook = False) Then
                    isCardSelected = True
                End If
            Loop
        End If

        Return iRandomCard  ' return the random card we selected

    End Function


    ' This method will be completed by the student in a Your Turn activity 
    ' This function is called by DoBetterAI() to more intelligently select a card to ask for, if possible
    Private Function GetBetterCard() As Integer

        
    End Function

    ' This method provided complete in the Activity Starter
    ' This method will call the GetGetterCard() method first, and if that fails fall back to DoAI().
    Private Function DoBetterAI() As Integer

        ' This method is the smarter artificial intelligence for the computer opponent.
        Dim iSelectedCard As Integer = NO_CARD_SELECTED

        ' first, see if we know about any of the human's cards that we can ask for
        iSelectedCard = GetBetterCard()
        If (iSelectedCard = NO_CARD_SELECTED) Then
            ' if we dont have any cards that the human player has asked for, just use the old DoAI() function 
            iSelectedCard = DoAI()
        End If

        Return iSelectedCard    ' this is the best card we can ask for

    End Function


    ' This method provided complete in the Activity Starter
    ' This function implements all the logic to take cards from one player and give to another
    Private Function TakeCards(ByVal player As PlayerType, ByVal targetCard As Integer) As Boolean

        Dim isCardFound As Boolean = False  ' assume the card is not found in the opponent's hand
        Dim iCardCount As Integer = 0       ' count of how many matching cards were found
        Dim iOpponent As Integer

        ' determine who the opponent is for future reference
        If (player = PlayerType.COMPUTER) Then
            iOpponent = PlayerType.HUMAN
        Else
            iOpponent = PlayerType.COMPUTER
        End If

        ' for each card in the deck
        For i = 0 To 51

            ' if this card's owning player is the opponent
            If (myGameState.deckOfCards(i).currentPlayer = iOpponent) Then

                ' if this card's card name matches the requested card's card name
                If (myGameState.deckOfCards(i).cardName = myGameState.deckOfCards(targetCard).cardName) Then

                    ' change the owner of the card to the requesting player
                    myGameState.deckOfCards(i).currentPlayer = player
                    isCardFound = True  ' flag that we found at least one card
                    iCardCount += 1     ' increment the card count
                End If
            End If
        Next

        ' if the player was successful in getting at least one card
        If (isCardFound) Then

            ' display a friendly message indicating which player took a card, and how many cards were taken
            If (player = PlayerType.COMPUTER) Then
                MsgBox("The computer takes " & Str(iCardCount) & " of your " & myGameState.deckOfCards(targetCard).cardName & " card(s)")
            Else
                MsgBox("You take " & Str(iCardCount) & " of the computer's " & myGameState.deckOfCards(targetCard).cardName & " card(s)")
            End If

            ' update both hands as they both changed
            DisplayHand(PlayerType.COMPUTER)
            DisplayHand(PlayerType.HUMAN)

        End If

        Return isCardFound  ' return flag indicating card was taken to the calling function
    End Function

    ' This method provided complete in the Activity Starter
    ' This function will draw a selected card at a slight offset from the rest of the hand
    Private Sub SelectCard(ByVal currentCard As Integer)

        ' first, unselect any previous card
        UnselectCard()

        ' if some new card was selected
        If (currentCard >= 0) Then

            ' now calculate the new "selected" card location by shifting the card up 10 pixels in the Y direction
            Dim newX = myGameState.deckOfCards(currentCard).mySprite.UpperLeft.X   ' no change to horizontal position
            Dim newY = myGameState.deckOfCards(currentCard).mySprite.UpperLeft.Y - CARD_SELECTION_OFFSET ' subtract pixels from Y position

            ' set the card sprite's upper-left coordinate to the selected location
            myGameState.deckOfCards(currentCard).mySprite.UpperLeft = New Point(newX, newY)

            ' save which card is currently selected for future reference
            myGameState.iCurrentCardSelected = currentCard

            ' repaint the screen to show the new card position
            Invalidate()
        End If

    End Sub

    ' This method provided complete in the Activity Starter
    ' This method will clear any current card selection and position the previously selected card back in the hand
    Private Sub UnselectCard()

        ' if there is currently some card selected
        If (myGameState.iCurrentCardSelected >= 0) Then

            ' calculate the new "unselected" card location 
            Dim player = myGameState.deckOfCards(myGameState.iCurrentCardSelected).currentPlayer    ' get the current player
            Dim newX = myGameState.deckOfCards(myGameState.iCurrentCardSelected).mySprite.UpperLeft.X   ' no change to horizontal position
            Dim newY = GetUnselectedCardY(player)   ' get unselected Y position for this player

            ' set the card sprite's upper-left coordinate to the unselected position
            myGameState.deckOfCards(myGameState.iCurrentCardSelected).mySprite.UpperLeft = New Point(newX, newY)

            ' indicate that no card is currently selected
            myGameState.iCurrentCardSelected = NO_CARD_SELECTED

        End If

        ' invalidate the screen so the new card position is drawn
        Invalidate()
    End Sub

    ' This method provided complete in the Activity Starter
    ' This function will just call SaveGame() when the button is clicked.
    Private Sub SaveButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveButton.Click

        ' When the user clicks the save button we just call the SaveGame() method to save the game
        SaveGame()

    End Sub


    ' This method provided complete in the Activity Starter
    ' This function will call LoadGame() when the button is clicked, and re-display the user's hands
    Private Sub LoadButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LoadButton.Click

        ' When the user clicks the load button we first call the LoadGame() method to load the game state
        LoadGame()

        ' after the game state has been reloaded we need to repaint the screen to show the new card layout
        DisplayHand(PlayerType.COMPUTER)
        DisplayHand(PlayerType.HUMAN)


    End Sub

    ' This method will be completed by the student in a Your Turn activity 
    ' This function is responsible for all logic involved with saving the current game.
    Private Sub SaveGame()

       

    End Sub


    ' This method will be completed by the student in a Your Turn activity 
    ' This function is responsible for all logic involved with loading a saved game.
    Private Sub LoadGame()
       
    End Sub


    
End Class