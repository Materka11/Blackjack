#include <utility>
#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>


#pragma once

#include "BlackjackGame.h"


namespace Blackjack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	

	
	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			game = new BlackjackGame();
			pictureBoxes = gcnew List<PictureBox^>();
		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete game;
		}

	protected:

	protected:
	private: System::Windows::Forms::Button^ button_start;
	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^ button_hit;
	private: System::Windows::Forms::Button^ button_stand;
	private: System::Windows::Forms::Label^ label_result;
	private: System::Windows::Forms::Button^ button_play_again;
	private: List<PictureBox^>^ pictureBoxes;


	private: System::Windows::Forms::ToolStripMenuItem^ startToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ playAgainToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ gameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ startToolStripMenuItem1;

	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ authorToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox_playerName;
	private: System::Windows::Forms::Label^ label_hind_playerName;
	private: System::Windows::Forms::TextBox^ textBox_bet;
	private: System::Windows::Forms::Label^ label_hind_bet;
	private: System::Windows::Forms::Label^ label_playerName;
	private: System::Windows::Forms::Label^ label_bet;
	private: System::Windows::Forms::ToolStripMenuItem^ playAgainToolStripMenuItem1;
	private: System::Windows::Forms::Label^ label_points_1;
	private: System::Windows::Forms::Label^ label_points_2;
	private: System::Windows::Forms::TextBox^ textBox_console;



		BlackjackGame* game;
		

		void setCards(const std::vector<std::pair<char, std::string>> cards, bool isPlayer) {
			System::Drawing::Point currentButtonStartLocation = this->button_start->Location;
			int currentButtonStartX = currentButtonStartLocation.X;
			int currentButtonStartY = currentButtonStartLocation.Y;

			int initialPictureBoxX = currentButtonStartX - 50;
			int pictureBoxYShift;
			if (isPlayer) {
				pictureBoxYShift = 100;
			}
			else {
				pictureBoxYShift = -175;
			}
			int initialPictureBoxY = currentButtonStartY + pictureBoxYShift;

			const int cardsShift = 100;

			for (size_t i = 0; i < cards.size(); ++i) {
				char rank = cards[i].first;
				std::string suit = cards[i].second;

				std::stringstream filenameStream;
				filenameStream << rank << "_" << suit << ".png";
				std::string filename = filenameStream.str();

				PictureBox^ newPictureBox = gcnew PictureBox();
				newPictureBox->Location = System::Drawing::Point(initialPictureBoxX + i * cardsShift, initialPictureBoxY);
				newPictureBox->Size = System::Drawing::Size(80, 120);

				newPictureBox->Image = gcnew Drawing::Bitmap("skins\\cards\\" + gcnew String(filename.c_str()));

				this->Controls->Add(newPictureBox);
				pictureBoxes->Add(newPictureBox);
			}
		}

		
		void showResult(GameResult result) {
			this->button_hit->Size = System::Drawing::Size(0, 0);
			this->button_stand->Size = System::Drawing::Size(0, 0);

			const int formWidth = this->ClientSize.Width;
			const int formHeight = this->ClientSize.Height;

			const int labelResultWidth = 200;
			const int labelResultHeight = 100;

			const int labelResultX = (formWidth - labelResultWidth) / 2;
			const int labelResultY = (formHeight - labelResultHeight) / 2;

			this->label_result->Size = System::Drawing::Size(labelResultWidth, labelResultHeight);
			this->label_result->Location = System::Drawing::Point(labelResultX, labelResultY);

			const int bet = game->getBet();

			String^ consoleText = this->textBox_console->Text;
			std::string playerName = game->getPlayerName();

			String^ playerNameString = msclr::interop::marshal_as<String^>(playerName);
			
			if (result == GameResult::PLAYER) {
				game->setBet(bet * 2);
				const int wonBet = game->getBet();
				String^ resultString = L"Player " + playerNameString + " won " + wonBet + "$" + Environment::NewLine;
				this->label_result->Text = resultString;

				array<String^>^ stringsToConcat = { consoleText, resultString };
				String^ newConsoleText = String::Concat(stringsToConcat);
				this->textBox_console->Text = newConsoleText;
			}
			else if (result == GameResult::DEALER) {
				String^ resultString = L"Dealer won" + Environment::NewLine + "Player " + playerNameString + " lost " + bet + "$" + Environment::NewLine;
				game->setBet(0);
				this->label_result->Text = resultString;

				array<String^>^ stringsToConcat = { consoleText, resultString };
				String^ newConsoleText = String::Concat(stringsToConcat);
				this->textBox_console->Text = newConsoleText;
			}
			else if (result == GameResult::DRAW) {
				String^ resultString = L"Draw" + Environment::NewLine;
				game->setBet(bet);
				this->label_result->Text = resultString;

				array<String^>^ stringsToConcat = { consoleText, resultString };
				String^ newConsoleText = String::Concat(stringsToConcat);
				this->textBox_console->Text = newConsoleText;
			}
			this->button_play_again->Size = System::Drawing::Size(150, 50);
		}

		void RemovePictureBoxes() {
			for each (PictureBox ^ pictureBox in pictureBoxes) {
				this->Controls->Remove(pictureBox); 
				delete pictureBox; 
			}
			pictureBoxes->Clear(); 
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obsługi projektanta — nie należy modyfikować
		/// jej zawartości w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->button_hit = (gcnew System::Windows::Forms::Button());
			this->button_stand = (gcnew System::Windows::Forms::Button());
			this->label_result = (gcnew System::Windows::Forms::Label());
			this->button_play_again = (gcnew System::Windows::Forms::Button());
			this->startToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->playAgainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->playAgainToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->authorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox_playerName = (gcnew System::Windows::Forms::TextBox());
			this->label_hind_playerName = (gcnew System::Windows::Forms::Label());
			this->textBox_bet = (gcnew System::Windows::Forms::TextBox());
			this->label_hind_bet = (gcnew System::Windows::Forms::Label());
			this->label_playerName = (gcnew System::Windows::Forms::Label());
			this->label_bet = (gcnew System::Windows::Forms::Label());
			this->label_points_1 = (gcnew System::Windows::Forms::Label());
			this->label_points_2 = (gcnew System::Windows::Forms::Label());
			this->textBox_console = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_start
			// 
			this->button_start->BackColor = System::Drawing::SystemColors::Window;
			this->button_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_start->Location = System::Drawing::Point(0, 0);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(0, 0);
			this->button_start->TabIndex = 0;
			this->button_start->Text = L"START";
			this->button_start->UseVisualStyleBackColor = false;
			this->button_start->Click += gcnew System::EventHandler(this, &MyForm::button_start_Click);
			// 
			// button_hit
			// 
			this->button_hit->BackColor = System::Drawing::SystemColors::Window;
			this->button_hit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_hit->Location = System::Drawing::Point(0, 0);
			this->button_hit->Name = L"button_hit";
			this->button_hit->Size = System::Drawing::Size(0, 0);
			this->button_hit->TabIndex = 1;
			this->button_hit->Text = L"HIT";
			this->button_hit->UseVisualStyleBackColor = false;
			this->button_hit->Click += gcnew System::EventHandler(this, &MyForm::button_hit_Click);
			// 
			// button_stand
			// 
			this->button_stand->BackColor = System::Drawing::SystemColors::Window;
			this->button_stand->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_stand->Location = System::Drawing::Point(0, 0);
			this->button_stand->Name = L"button_stand";
			this->button_stand->Size = System::Drawing::Size(0, 0);
			this->button_stand->TabIndex = 2;
			this->button_stand->Text = L"STAND";
			this->button_stand->UseVisualStyleBackColor = false;
			this->button_stand->Click += gcnew System::EventHandler(this, &MyForm::button_stand_Click);
			// 
			// label_result
			// 
			this->label_result->BackColor = System::Drawing::Color::Transparent;
			this->label_result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_result->ForeColor = System::Drawing::SystemColors::Window;
			this->label_result->Location = System::Drawing::Point(0, 0);
			this->label_result->Name = L"label_result";
			this->label_result->Size = System::Drawing::Size(0, 0);
			this->label_result->TabIndex = 3;
			this->label_result->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_play_again
			// 
			this->button_play_again->BackColor = System::Drawing::SystemColors::Window;
			this->button_play_again->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button_play_again->Location = System::Drawing::Point(0, 0);
			this->button_play_again->Name = L"button_play_again";
			this->button_play_again->Size = System::Drawing::Size(0, 0);
			this->button_play_again->TabIndex = 4;
			this->button_play_again->Text = L"PLAY AGAIN";
			this->button_play_again->UseVisualStyleBackColor = false;
			this->button_play_again->Click += gcnew System::EventHandler(this, &MyForm::button_play_again_Click);
			// 
			// startToolStripMenuItem
			// 
			this->startToolStripMenuItem->Name = L"startToolStripMenuItem";
			this->startToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// playAgainToolStripMenuItem
			// 
			this->playAgainToolStripMenuItem->Name = L"playAgainToolStripMenuItem";
			this->playAgainToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->gameToolStripMenuItem,
					this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(984, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->startToolStripMenuItem1,
					this->playAgainToolStripMenuItem1
			});
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->gameToolStripMenuItem->Text = L"Game";
			// 
			// startToolStripMenuItem1
			// 
			this->startToolStripMenuItem1->Name = L"startToolStripMenuItem1";
			this->startToolStripMenuItem1->Size = System::Drawing::Size(128, 22);
			this->startToolStripMenuItem1->Text = L"Start";
			this->startToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::startToolStripMenuItem1_Click);
			// 
			// playAgainToolStripMenuItem1
			// 
			this->playAgainToolStripMenuItem1->Name = L"playAgainToolStripMenuItem1";
			this->playAgainToolStripMenuItem1->Size = System::Drawing::Size(128, 22);
			this->playAgainToolStripMenuItem1->Text = L"Play again";
			this->playAgainToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::playAgainToolStripMenuItem1_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->authorToolStripMenuItem });
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// authorToolStripMenuItem
			// 
			this->authorToolStripMenuItem->Name = L"authorToolStripMenuItem";
			this->authorToolStripMenuItem->Size = System::Drawing::Size(111, 22);
			this->authorToolStripMenuItem->Text = L"Author";
			this->authorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::authorToolStripMenuItem_Click);
			// 
			// textBox_playerName
			// 
			this->textBox_playerName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBox_playerName->Location = System::Drawing::Point(0, 0);
			this->textBox_playerName->Name = L"textBox_playerName";
			this->textBox_playerName->Size = System::Drawing::Size(0, 31);
			this->textBox_playerName->TabIndex = 6;
			// 
			// label_hind_playerName
			// 
			this->label_hind_playerName->BackColor = System::Drawing::Color::Transparent;
			this->label_hind_playerName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_hind_playerName->ForeColor = System::Drawing::SystemColors::Control;
			this->label_hind_playerName->Location = System::Drawing::Point(0, 0);
			this->label_hind_playerName->Name = L"label_hind_playerName";
			this->label_hind_playerName->Size = System::Drawing::Size(0, 0);
			this->label_hind_playerName->TabIndex = 7;
			this->label_hind_playerName->Text = L"Enter your name";
			// 
			// textBox_bet
			// 
			this->textBox_bet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_bet->Location = System::Drawing::Point(0, 0);
			this->textBox_bet->Name = L"textBox_bet";
			this->textBox_bet->Size = System::Drawing::Size(0, 31);
			this->textBox_bet->TabIndex = 6;
			// 
			// label_hind_bet
			// 
			this->label_hind_bet->BackColor = System::Drawing::Color::Transparent;
			this->label_hind_bet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_hind_bet->ForeColor = System::Drawing::SystemColors::Control;
			this->label_hind_bet->Location = System::Drawing::Point(0, 0);
			this->label_hind_bet->Name = L"label_hind_bet";
			this->label_hind_bet->Size = System::Drawing::Size(0, 0);
			this->label_hind_bet->TabIndex = 7;
			this->label_hind_bet->Text = L"Enter your bet";
			// 
			// label_playerName
			// 
			this->label_playerName->AutoSize = true;
			this->label_playerName->BackColor = System::Drawing::Color::Transparent;
			this->label_playerName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_playerName->ForeColor = System::Drawing::SystemColors::Control;
			this->label_playerName->Location = System::Drawing::Point(0, 0);
			this->label_playerName->Name = L"label_playerName";
			this->label_playerName->Size = System::Drawing::Size(0, 44);
			this->label_playerName->TabIndex = 8;
			// 
			// label_bet
			// 
			this->label_bet->AutoSize = true;
			this->label_bet->BackColor = System::Drawing::Color::Transparent;
			this->label_bet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_bet->ForeColor = System::Drawing::SystemColors::Control;
			this->label_bet->Location = System::Drawing::Point(0, 0);
			this->label_bet->Name = L"label_bet";
			this->label_bet->Size = System::Drawing::Size(0, 44);
			this->label_bet->TabIndex = 8;
			// 
			// label_points_1
			// 
			this->label_points_1->AutoSize = true;
			this->label_points_1->BackColor = System::Drawing::Color::Transparent;
			this->label_points_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_points_1->ForeColor = System::Drawing::SystemColors::Control;
			this->label_points_1->Location = System::Drawing::Point(0, 0);
			this->label_points_1->Name = L"label_points_1";
			this->label_points_1->Size = System::Drawing::Size(0, 44);
			this->label_points_1->TabIndex = 9;
			// 
			// label_points_2
			// 
			this->label_points_2->AutoSize = true;
			this->label_points_2->BackColor = System::Drawing::Color::Transparent;
			this->label_points_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_points_2->ForeColor = System::Drawing::SystemColors::Control;
			this->label_points_2->Location = System::Drawing::Point(0, 0);
			this->label_points_2->Name = L"label_points_2";
			this->label_points_2->Size = System::Drawing::Size(0, 44);
			this->label_points_2->TabIndex = 10;
			// 
			// textBox_console
			// 
			this->textBox_console->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_console->Location = System::Drawing::Point(0, 0);
			this->textBox_console->Multiline = true;
			this->textBox_console->Name = L"textBox_console";
			this->textBox_console->ReadOnly = true;
			this->textBox_console->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_console->ShortcutsEnabled = false;
			this->textBox_console->Size = System::Drawing::Size(100, 20);
			this->textBox_console->TabIndex = 11;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 559);
			this->Controls->Add(this->textBox_console);
			this->Controls->Add(this->label_points_2);
			this->Controls->Add(this->label_points_1);
			this->Controls->Add(this->label_playerName);
			this->Controls->Add(this->label_bet);
			this->Controls->Add(this->label_hind_playerName);
			this->Controls->Add(this->textBox_playerName);
			this->Controls->Add(this->label_hind_bet);
			this->Controls->Add(this->textBox_bet);
			this->Controls->Add(this->button_play_again);
			this->Controls->Add(this->label_result);
			this->Controls->Add(this->button_stand);
			this->Controls->Add(this->button_hit);
			this->Controls->Add(this->button_start);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = FormWindowState::Maximized;

		const int formWidth = this->ClientSize.Width;
		const int formHeight = this->ClientSize.Height;

		const int buttonStartWidth = 150;
		const int buttonStartHeight = 50;

		const int buttonStartX = (formWidth - buttonStartWidth) / 2;
		const int buttonStartY = (formHeight - buttonStartHeight) / 2;

		this->button_start->Size = System::Drawing::Size(buttonStartWidth, buttonStartHeight);
		this->button_start->Location = System::Drawing::Point(buttonStartX, buttonStartY);

		const int buttonPlayAgainX = buttonStartX;
		const int buttonPlayAgainY = buttonStartY + 300;

		this->button_play_again->Location = System::Drawing::Point(buttonPlayAgainX, buttonPlayAgainY);

		const int textBoxWidth = 400;
		const int textBoxHeight = 31;

		const int textBox_playerNameX = (formWidth - textBoxWidth) / 2;
		const int textBox_playerNameY = (formHeight - textBoxHeight) / 2 - 250;

		this->textBox_playerName->Size = System::Drawing::Size(textBoxWidth, textBoxHeight);
		this->textBox_playerName->Location = System::Drawing::Point(textBox_playerNameX, textBox_playerNameY);

		const int label_hint_playerNameWidth = 170;
		const int label_hint_playerNameHeight = 25;

		const int label_hint_playerNameX = (formWidth - label_hint_playerNameWidth) / 2;
		const int label_hint_playerNameY = (formHeight - label_hint_playerNameHeight) / 2 - 300;

		this->label_hind_playerName->Size = System::Drawing::Size(label_hint_playerNameWidth, label_hint_playerNameHeight);
		this->label_hind_playerName->Location = System::Drawing::Point(label_hint_playerNameX, label_hint_playerNameY);

		const int textBox_betX = (formWidth - textBoxWidth) / 2;
		const int textBox_betY = (formHeight - textBoxHeight) / 2 - 125;

		this->textBox_bet->Size = System::Drawing::Size(textBoxWidth, textBoxHeight);
		this->textBox_bet->Location = System::Drawing::Point(textBox_betX, textBox_betY);

		const int label_hint_betWidth = 150;
		const int label_hint_betHeight = 25;

		const int label_hint_betX = (formWidth - label_hint_betWidth) / 2;
		const int label_hint_betY = (formHeight - label_hint_betHeight) / 2 - 175;

		this->label_hind_bet->Size = System::Drawing::Size(label_hint_betWidth, label_hint_betHeight);
		this->label_hind_bet->Location = System::Drawing::Point(label_hint_betX, label_hint_betY);

		const int textBox_consoleWidth = 200;
		const int textBox_consoleHeight = 100;

		const int textBox_consoleX = formWidth - textBox_consoleWidth - 50;
		const int textBox_consoleY = formHeight - textBox_consoleHeight - 50;

		this->textBox_console->Size = System::Drawing::Size(textBox_consoleWidth, textBox_consoleHeight);
		this->textBox_console->Location = System::Drawing::Point(textBox_consoleX, textBox_consoleY);

	}

	private: System::Void button_start_Click(System::Object^ sender, System::EventArgs^ e) {
		game->startGame();

		const std::vector<std::pair<char, std::string>> playerCards = game->getCards(true);
		setCards(playerCards, true);

		const std::vector<std::pair<char, std::string>> dealerCards = game->getCards(false);
		setCards(dealerCards, false);

		String ^ playerName = textBox_playerName->Text;
		std::string unmanagedPlayerName = msclr::interop::marshal_as<std::string>(playerName);
		game->setPlayerName(unmanagedPlayerName);

		String^ bet = textBox_bet->Text;
		int intBet = 0;

		try {
			intBet = System::Convert::ToInt32(bet);
		}
		catch (System::FormatException^) {
			
		}
		game->setBet(intBet);


		this->button_start->Size = System::Drawing::Size(0, 0);
		this->label_hind_playerName->Size = System::Drawing::Size(0, 0);
		this->label_hind_playerName->Text = "";
		this->textBox_playerName->Size = System::Drawing::Size(0, 0);
		this->label_hind_bet->Size = System::Drawing::Size(0, 0);
		this->label_hind_bet->Text = "";
		this->textBox_bet->Size = System::Drawing::Size(0, 0);

		const int buttonShiftY = 300;
		const int buttonHitShiftX = -100;
		const int buttonStandShiftX = 100;

		System::Drawing::Point currentButtonStartLocation = this->button_start->Location;
		const int currentButtonStartX = currentButtonStartLocation.X;
		const int currentButtonStartY = currentButtonStartLocation.Y;

		const int buttonY = currentButtonStartY + buttonShiftY;
		const int buttonHitX = currentButtonStartX + buttonHitShiftX;
		const int buttonStandX = currentButtonStartX + buttonStandShiftX;
		
		this->button_hit->Size = System::Drawing::Size(150, 50);
		this->button_hit->Location = System::Drawing::Point(buttonHitX, buttonY);

		this->button_stand->Size = System::Drawing::Size(150, 50);
		this->button_stand->Location = System::Drawing::Point(buttonStandX, buttonY);

		this->label_playerName->Text = "Player Name: " + playerName;
		this->label_playerName->Location = System::Drawing::Point(currentButtonStartX - 700, currentButtonStartY - 350);

		this->label_bet->Text = "Bet: " + intBet.ToString() + "$";
		this->label_bet->Location = System::Drawing::Point(currentButtonStartX - 700, currentButtonStartY + 400);

		String^ consoleText = this->textBox_console->Text;

		String^ playerNameString = "Player " + playerName;
		String^ betString = " bet " + intBet.ToString() + "$" + Environment::NewLine;

		array<String^>^ stringsToConcat = { consoleText, playerNameString, betString };
		String^ newConsoleText = String::Concat(stringsToConcat);

		this->textBox_console->Text = newConsoleText;

		const int dealerPoints = game->getPoints(false);
		this->label_points_1->Location = System::Drawing::Point(currentButtonStartX + 375, currentButtonStartY - 150);
		this->label_points_1->Text = "Dealer points: " + dealerPoints.ToString();
		

		const int playerPoints = game->getPoints(true);
		this->label_points_2->Location = System::Drawing::Point(currentButtonStartX + 375, currentButtonStartY + 150);
		this->label_points_2->Text = "Player points: " + playerPoints.ToString();

		if (playerPoints == 21) {
			showResult(PLAYER);
		}
	}

	private: System::Void button_hit_Click(System::Object^ sender, System::EventArgs^ e) {
		game->hit();

		const std::vector<std::pair<char, std::string>> playerCards = game->getCards(true);
		setCards(playerCards, true);

		const std::vector<std::pair<char, std::string>> dealerCards = game->getCards(false);
		setCards(dealerCards, false);

		String^ consoleText = this->textBox_console->Text;
		std::string playerName = game->getPlayerName();

		String^ playerNameString = msclr::interop::marshal_as<String^>(playerName);
		String^ hitString = "Player " + playerNameString + " hit" + Environment::NewLine;

		array<String^>^ stringsToConcat = { consoleText, hitString };
		String^ newConsoleText = String::Concat(stringsToConcat);

		this->textBox_console->Text = newConsoleText;

		const int playerPoints = game->getPoints(true);
		this->label_points_2->Text = "Player points: " + playerPoints.ToString();

		const GameResult result = game->giveResultHit();

		if (result == PLAYER) {
			showResult(PLAYER);
		}
		else if (result == DEALER) {
			showResult(DEALER);
		}
	}

	private: System::Void button_stand_Click(System::Object^ sender, System::EventArgs^ e) {
		const GameResult result = game->stand();

		const std::vector<std::pair<char, std::string>> dealerCards = game->getCards(false);
		setCards(dealerCards, false);

		String^ consoleText = this->textBox_console->Text;
		std::string playerName = game->getPlayerName();

		String^ playerNameString = msclr::interop::marshal_as<String^>(playerName);
		String^ standString = "Player " + playerNameString + " stand" + Environment::NewLine;

		array<String^>^ stringsToConcat = { consoleText, standString };
		String^ newConsoleText = String::Concat(stringsToConcat);

		this->textBox_console->Text = newConsoleText;

		const int dealerPoints = game->getPoints(false);
		this->label_points_1->Text = "Dealer points: " + dealerPoints.ToString();

		if (result == PLAYER) {
			showResult(PLAYER);
		}
		else if (result == DEALER) {	
			showResult(DEALER);
		}
		else if (result == DRAW) {	
			showResult(DRAW);
		}
	}
	private: System::Void button_play_again_Click(System::Object^ sender, System::EventArgs^ e) {
		game->resetGame();

		RemovePictureBoxes();

		this->button_play_again->Size = System::Drawing::Size(0, 0);
		this->label_result->Size = System::Drawing::Size(0, 0);
		this->button_stand->Size = System::Drawing::Size(0, 0);
		this->button_hit->Size = System::Drawing::Size(0, 0);
		this->label_playerName->Text = "";
		this->label_bet->Text = "";
		this->button_start->Size = System::Drawing::Size(150, 50);
		this->label_hind_playerName->Size = System::Drawing::Size(170, 25);
		this->label_hind_playerName->Text = L"Enter your name";
		this->textBox_playerName->Size = System::Drawing::Size(400, 31);
		this->label_hind_bet->Size = System::Drawing::Size(150, 25);
		this->label_hind_bet->Text = L"Enter your bet";
		this->textBox_bet->Size = System::Drawing::Size(400, 31);
		this->label_points_1->Text = "";
		this->label_points_2->Text = "";
	}

	private: System::Void startToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		button_start_Click(sender, e);
	}

	private: System::Void authorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::MessageBox::Show("Dzien dobry, nazywam sie Arkadiusz i jestem autorem tej pracy, programuje od 2017 roku, a pracuje od 2022. Zapraszam na mojego githuba: https://github.com/materka11 lub na moja strone: https://arkadiuszmaterka.pl/");
	}
	private: System::Void playAgainToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		button_play_again_Click(sender, e);
	}
};
}
