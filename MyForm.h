#include <utility>
#include <string>
#include <sstream>


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

			const int labelResultWidth = 150;
			const int labelResultHeight = 50;

			const int labelResultX = (formWidth - labelResultWidth) / 2;
			const int labelResultY = (formHeight - labelResultHeight) / 2;

			this->label_result->Size = System::Drawing::Size(labelResultWidth, labelResultHeight);
			this->label_result->Location = System::Drawing::Point(labelResultX, labelResultY);
			
			if (result == GameResult::PLAYER) {
				this->label_result->Text = L"Gracz wygrał";
			}
			else if (result == GameResult::DEALER) {
				this->label_result->Text = L"Krupier wygrał";
			}
			else if (result == GameResult::DRAW) {
				this->label_result->Text = L"Remis";
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
			this->SuspendLayout();
			// 
			// button_start
			// 
			this->button_start->BackColor = System::Drawing::SystemColors::Window;
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
			this->label_result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->button_play_again->Location = System::Drawing::Point(0, 0);
			this->button_play_again->Name = L"button_play_again";
			this->button_play_again->Size = System::Drawing::Size(0, 0);
			this->button_play_again->TabIndex = 4;
			this->button_play_again->Text = L"Zagraj ponownie";
			this->button_play_again->UseVisualStyleBackColor = false;
			this->button_play_again->Click += gcnew System::EventHandler(this, &MyForm::button_play_again_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 559);
			this->Controls->Add(this->button_play_again);
			this->Controls->Add(this->label_result);
			this->Controls->Add(this->button_stand);
			this->Controls->Add(this->button_hit);
			this->Controls->Add(this->button_start);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

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
	}

	private: System::Void button_start_Click(System::Object^ sender, System::EventArgs^ e) {
		game->startGame();

		const std::vector<std::pair<char, std::string>> playerCards = game->getCards(true);
		setCards(playerCards, true);

		const std::vector<std::pair<char, std::string>> dealerCards = game->getCards(false);
		setCards(dealerCards, false);

		this->button_start->Size = System::Drawing::Size(0, 0);

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

		const int playerPoints = game->getPoints(true);

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

		const int playerPoints = game->getPoints(true);

		if (playerPoints == 21) {
			showResult(PLAYER);
		}
		else if (playerPoints > 21) {
			showResult(DEALER);
		}
	}

	private: System::Void button_stand_Click(System::Object^ sender, System::EventArgs^ e) {
		GameResult result = game->stand();

		const std::vector<std::pair<char, std::string>> dealerCards = game->getCards(false);
		setCards(dealerCards, false);

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

		this->button_play_again->Size = System::Drawing::Size(0, 0);
		this->label_result->Size = System::Drawing::Size(0, 0);
		this->button_hit->Size = System::Drawing::Size(150, 50);
		this->button_stand->Size = System::Drawing::Size(150, 50);

		RemovePictureBoxes();

		const std::vector<std::pair<char, std::string>> playerCards = game->getCards(true);
		setCards(playerCards, true);

		const std::vector<std::pair<char, std::string>> dealerCards = game->getCards(false);
		setCards(dealerCards, false);
	}
};
}
