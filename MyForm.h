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
		BlackjackGame* game;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obsługi projektanta — nie należy modyfikować
		/// jej zawartości w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_start
			// 
			this->button_start->BackColor = System::Drawing::SystemColors::Window;
			this->button_start->Name = L"button_start";
			this->button_start->TabIndex = 0;
			this->button_start->Text = L"START";
			this->button_start->UseVisualStyleBackColor = false;
			this->button_start->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 559);
			this->Controls->Add(this->button_start);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
		this->WindowState = FormWindowState::Maximized;

		int formWidth = this->ClientSize.Width;
		int formHeight = this->ClientSize.Height;

		int buttonStartWidth = 150;
		int buttonStartHeight = 50;

		int buttonStartX = (formWidth - buttonStartWidth) / 2;
		int buttonStartY = (formHeight - buttonStartHeight) / 2;

		this->button_start->Size = System::Drawing::Size(buttonStartWidth, buttonStartHeight);
		this->button_start->Location = System::Drawing::Point(buttonStartX, buttonStartY);


		game->startGame();

		const int cardsShift = 100;

		const std::vector<std::pair<char, std::string>> playerCards = game->getCardsPlayer();

		int initialPlayerPictureBoxX = buttonStartX - 50;
		int initialPlayerPictureBoxY = buttonStartY + 100;


		for (size_t i = 0; i < playerCards.size(); ++i) {
			char rank = playerCards[i].first;
			std::string suit = playerCards[i].second;

			std::stringstream filenameStream;
			filenameStream << rank << "_" << suit << ".png";
			std::string filename = filenameStream.str();

			PictureBox^ newPictureBox = gcnew PictureBox();
			newPictureBox->Location = System::Drawing::Point(initialPlayerPictureBoxX + i * cardsShift, initialPlayerPictureBoxY);
			newPictureBox->Size = System::Drawing::Size(80, 120); 

			newPictureBox->Image = gcnew Drawing::Bitmap("skins\\cards\\" + gcnew String(filename.c_str()));

			this->Controls->Add(newPictureBox);
		}

		const std::vector<std::pair<char, std::string>> dealerCards = game->getCardsDealer();

		int initialDealerPictureBoxX = buttonStartX - 50;
		int initialDealerPictureBoxY = buttonStartY - 175;


		for (size_t i = 0; i < dealerCards.size(); ++i) {
			char rank = dealerCards[i].first;
			std::string suit = dealerCards[i].second;

			std::stringstream filenameStream;
			filenameStream << rank << "_" << suit << ".png";
			std::string filename = filenameStream.str();

			PictureBox^ newPictureBox = gcnew PictureBox();
			newPictureBox->Location = System::Drawing::Point(initialDealerPictureBoxX + i * cardsShift, initialDealerPictureBoxY);
			newPictureBox->Size = System::Drawing::Size(80, 120);

			newPictureBox->Image = gcnew Drawing::Bitmap("skins\\cards\\" + gcnew String(filename.c_str()));

			this->Controls->Add(newPictureBox);
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
